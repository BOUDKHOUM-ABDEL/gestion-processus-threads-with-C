#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork(); // Création du premier fils
    if (pid1 < 0) {
        perror("Échec de fork pour le premier fils");
        exit(1);
    }
    else if (pid1 == 0) {
        // Code du premier fils
        printf("Premier fils (PID = %d, PPID = %d)\n", getpid(), getppid());
        for (int i = 1; i <= 50; i++) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    // Code du père continue
    pid2 = fork(); // Création du deuxième fils
    if (pid2 < 0) {
        perror("Échec de fork pour le deuxième fils");
        exit(1);
    }
    else if (pid2 == 0) {
        // Code du deuxième fils
        printf("Deuxième fils (PID = %d, PPID = %d)\n", getpid(), getppid());
        for (int i = 51; i <= 100; i++) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    // Code du père : il attend les deux fils
    wait(NULL); // Attend un des deux fils
    wait(NULL); // Attend l'autre fils

    printf("Processus père (PID = %d) : tous les fils sont terminés.\n", getpid());
    return 0;
}
