#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork(); // Cr�ation du premier fils
    if (pid1 < 0) {
        perror("�chec de fork pour le premier fils");
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

    // Code du p�re continue
    pid2 = fork(); // Cr�ation du deuxi�me fils
    if (pid2 < 0) {
        perror("�chec de fork pour le deuxi�me fils");
        exit(1);
    }
    else if (pid2 == 0) {
        // Code du deuxi�me fils
        printf("Deuxi�me fils (PID = %d, PPID = %d)\n", getpid(), getppid());
        for (int i = 51; i <= 100; i++) {
            printf("%d ", i);
        }
        printf("\n");
        exit(0);
    }

    // Code du p�re : il attend les deux fils
    wait(NULL); // Attend un des deux fils
    wait(NULL); // Attend l'autre fils

    printf("Processus p�re (PID = %d) : tous les fils sont termin�s.\n", getpid());
    return 0;
}
