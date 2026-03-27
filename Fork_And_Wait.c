#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("24SJPCCSL407 ");
    } 
    else {
        wait(NULL);
        printf("Operating Systems Lab");
    }
    return 0;
}