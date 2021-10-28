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

    return (int)getpid();
}

void sig_handler(int sig) {
   
    printf("%d", sig);
    pid_t pid = fork();

    if (pid==0)
    {
        printf("child");
    }
    else {
        printf("Parent");
   }
    
}
