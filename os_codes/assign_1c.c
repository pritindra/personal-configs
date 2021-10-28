#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

    pid_t pid = fork();         // first fork

    if (pid == 0) {
        
        char *args[] = {"./prog_eg", NULL};
        
        printf("Program name: %s\n", argv[0]);  // program name 
        execv(args[0], args);                   // executing prog_eg.c
                    
        
    }

    int status;
    waitpid(pid, &status, 0);       // getting status of the child

    if (WIFEXITED(status)){
        wait(&status);              // waiting for child to complete
    }
    exit(0);
}  
