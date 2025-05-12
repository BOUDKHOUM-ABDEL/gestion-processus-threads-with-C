#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5 // حجم المخزن
#define PRODUCE_COUNT 10

int buffer[SIZE];
int in = 0;
int out = 0;

sem_t empty;  // عدد الخانات الفارغة
sem_t full;   // عدد الخانات المملوءة
pthread_mutex_t mutex;  // لقفل القسم الحرج

void* producer(void* arg) {
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        int item = rand() % 100;

        sem_wait(&empty);                // الانتظار حتى وجود خانة فارغة
        pthread_mutex_lock(&mutex);      // دخول القسم الحرج

        buffer[in] = item;
        printf("🔵 المنتج أنتج: %d في الخانة %d\n", item, in);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);    // الخروج من القسم الحرج
        sem_post(&full);                 // إشارة بوجود عنصر جديد

        sleep(1); // لتقليد وقت الإنتاج
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        sem_wait(&full);                 // انتظار وجود عنصر
        pthread_mutex_lock(&mutex);      // دخول القسم الحرج

        int item = buffer[out];
        printf("🟠 المستهلك استهلك: %d من الخانة %d\n", item, out);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);    // الخروج من القسم الحرج
        sem_post(&empty);                // إشارة بوجود خانة فارغة

        sleep(2); // لتقليد وقت الاستهلاك
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // تهيئة السيمَافُورات والقفل
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // إنشاء الـ threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // الانتظار حتى انتهاء التنفيذ
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // تحرير الموارد
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
