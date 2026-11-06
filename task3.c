#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t c1, c2;

    c1 = fork();

    if (c1 == 0) {
        execlp("date", "date", NULL);
        perror("exec failed");
        return 1;
    } 
    else if (c1 > 0) {
        c2 = fork();

        if (c2 == 0) {
            execlp("ls", "ls", "-l", NULL);
            perror("exec failed");
            return 1;
        } 
        else if (c2 > 0) {
            wait(NULL);
            wait(NULL);
            printf("Both child processes have completed.\n");
        } 
        else {
            perror("fork failed");
        }
    } 
    else {
        perror("fork failed");
    }

    return 0;
}
