#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent process started. PID = %d\n", getpid());

    pid = fork();

    if (pid == 0) {
        printf("Child process created. PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Child running...\n");
        sleep(3);
        printf("Child finished.\n");
    } 
    else if (pid > 0) {
        for (int i = 0; i < 3; i++) {
            printf("Parent is waiting...\n");
            sleep(1);
        }
        wait(NULL);
        printf("Parent detected child termination.\n");
    }

    return 0;
}
