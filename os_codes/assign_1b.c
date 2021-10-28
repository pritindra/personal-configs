#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<utmp.h>

int main(int argc, char *argv[]) 
{

    char roll[] = "CSB19041";
    pid_t arr[10];          
    int i = 0;
    FILE *fptr;
    int countCh = 0;            
    int countGc = 0;            // counts and printing pids 
    pid_t pid = fork();         // first fork

    if (pid == 0) {
        printf("Parent process ID = %d\n", (int) getppid());
        printf("Child process ID = %d\n", (int) getpid());
        
        arr[i] = getpid();
        fopen("out.txt", "w");
        countCh = countCh + 1;
        fprintf(fptr,"%d \n", countCh);
        fclose(fptr);

        pid = fork();           // second fork
        if (pid == 0) {
            printf("Roll No. = %s\n", roll);// printing roll no.
            system("who");          // printing logged in user
            
            fopen("out.txt", "w");
            fprintf(fptr,"1 \n");
            fclose(fptr);
            
            struct utmp *tmp;
            setutent();
            tmp = getutent();
            while (tmp)
            {
                if(tmp->ut_type==USER_PROCESS) {
                    printf("%9s \n", tmp->ut_user);
                }
                tmp = getutent();
            }
            arr[i++] = getpid();
            printf("GC Process ID = %d\n", (int) getpid());
            printf("Child Process ID = %d\n", (int) getppid());

            exit(0);
        }

        else if (pid<0){
            exit(1);
        }

        else {
            wait(NULL);
        }
    exit(0);
    }

    else if (pid<0){
        exit(1);
    }

    else {
        wait(NULL);                 // parent process
        arr[i++] = getpid();
    
        printf("Count of children and grandchildren = %d,%d\n", countCh,countGc);       // parent processes
        printf("All pids and ppids are \n");
        for(int loop = 0; loop < 3; loop++)
            printf("%d ", arr[loop]);
        printf("\n");
    }
    exit(0);
}  
