#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Échec du fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Code du fils
        printf("Fils : PID = %d, je termine.\n", getpid());
        exit(0);
    }
    else {
        // Code du père : attend avant de faire wait()
        printf("Père : PID = %d, je dors 15 secondes avant wait().\n", getpid());
        sleep(15); // Durant ce temps, le fils est zombie
        wait(&status);
        printf("Père : J’ai récupéré la fin du fils.\n");
    }

    return 0;
}
