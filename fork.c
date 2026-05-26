#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int i;

    for(i = 0; i < 3; i++) {

        pid_t pid = fork();

        if(pid == 0) {
            // Child Process
            printf("Child Process %d\n", i+1);
            printf("Child PID = %d\n", getpid());
            printf("Parent PID = %d\n\n", getppid());
            return 0;
        }
    }

    // Parent Process
    printf("Parent Process\n");
    printf("Parent PID = %d\n", getpid());

    return 0;
}
