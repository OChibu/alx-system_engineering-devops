#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    for (int i = 0; i < 5; i++) {
        pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            exit(0);
        } else {
            // Parent process
            printf("Zombie process created, PID: %d\n", pid);
            sleep(1);
        }
    }

    // Code to wait for user input
    printf("Press enter to exit\n");
    getchar();

    return 0;
}
