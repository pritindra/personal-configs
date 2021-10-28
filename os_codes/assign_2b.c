#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main() {

    pid_t pid = fork();     // first fork
    
    if (pid==0) {
        printf("PID: %d\n", (int) getpid()); // printing pid of child

    }
    else if(pid<0) {
        exit(1);
    }
    else {
        wait(NULL);
        printf("Sig ID: %d\n", SIGKILL);    // print signal id
        kill(pid, SIGKILL);             // killing the parent process
    }

    exit(0);
}
