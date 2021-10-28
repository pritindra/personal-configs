#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

// void sig_handler(int sig);     // declaration of signal handler function

int main() {

    void sig_handler(int sig);     // declaration of signal handler function
    int i;
    signal(SIGINT, sig_handler);
    printf("Enter something:: ");
    scanf("%d",&i);             // taking input from user for successful termination

    return 0;
}

void sig_handler(int sig) {
    
    if (!fork()) {
        printf("PID: %d\n", (int) getpid());    // parent process
        printf("PPID: %d\n", (int) getppid());
    }
    else {
        printf("From child.");                  // child process
        printf("PID: %d\n", (int) getpid());
        printf("PPID: %d\n", (int) getppid());
        exit(0);  
    }
}
