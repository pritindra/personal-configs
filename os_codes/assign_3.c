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
    printf("Start Interrupt :: ");
    scanf("%d",&i);             // taking input from user for successful termination

    return 0;
}

void sig_handler(int sig) {
    
    int N;
    int pfds[2];
    int buf[N];
    pipe(pfds);

    printf("Enter N :: \n");
    scanf("%d", &N);
    if (!fork()) {
        int* a = (int*)malloc(N*sizeof(int));
        *(a+0) = 0;
        *(a+1) = 1;

        for (int i=0; i<N; ++i) {
            *(a+i+2) = *(a+i) + (*(a+i+1));
        }
        close(pfds[0]);
        write(pfds[1], a, N*sizeof(int));
    
        exit(0);

    }
    else {
        close(pfds[1]); 
        read(pfds[0], buf, N*sizeof(int));
        printf("PARENT: read %d\n", *buf);
        wait(NULL);
    }
}
