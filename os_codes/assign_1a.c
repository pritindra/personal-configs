#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]) {

    char roll[] = "CSB19041";    // storing roll no.
    pid_t pid = fork();         // first fork()
    int countCh = 0;
    int countGc = 0;   // counters
    int i=0;

    if (pid == 0) {
        printf("Parent process ID = %d\n", (int) getppid());
        countCh = countCh + 1;
        pid = fork();   //second fork()
        
        if (pid == 0) {
            printf("Roll No. = %s\n", roll);    // grand child processes
            countGc ++;
            countCh = countCh + 2;
            printf("GC Process ID = %d\n", (int) getpid());    //child processes
            printf("Child Process ID = %d\n", (int) getppid());    //child processes
            exit(0);
        }

        else if (pid<0){
            exit(1);
        }

        else {
            exit(0);
        }
    }

    else if (pid<0){
        exit(1);
    }

    else {
        printf("All pids and ppids are ");

        printf("\n");
        printf("Count of children and grandchildren = %d,%d\n", countCh,countGc);       // parent processes
    }


    exit(0);
}  
