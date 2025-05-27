#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erreur de fork");
        exit(1);
    }
    else if (pid == 0) {
        // Code du processus fils
        printf("Fils (PID = %d) : Je termine maintenant.\n", getpid());
        exit(0); // Le fils se termine imm�diatement
    }
    else {
        // Code du p�re : ne fait pas de wait()
        printf("P�re (PID = %d) : Le fils est devenu un zombie pendant 30 secondes.\n", getpid());
        sleep(30); // Attente de 30 secondes
        printf("P�re : Fin du sommeil, maintenant je me termine.\n");
    }

    return 0;
}
