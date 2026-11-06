#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        return 1;
    } 
    else if (pid > 0) {
        wait(NULL);
        printf("Child execution completed.\n");
    }

    return 0;
}
