#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int glbVar = 0;

int main() {
    int lclVar = 0;

    pid_t pid = fork();

    switch(pid) {
        case 0:
            glbVar++;
            lclVar++;
            break;
        default:
            glbVar += 20;
            lclVar += 10;

            int status;
            wait(&status);
    }

    printf("Process %d: glbVar = %d, lclVar = %d\n", getpid(), glbVar, lclVar);
    return 0;
}
