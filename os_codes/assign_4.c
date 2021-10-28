#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    
    struct flock f1 = {F_RDLCK, SEEK_SET, 0, 0, 0};
    int fd;

    f1.l_pid = getpid();

    if ((fd = open("assign_4.c", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }

    printf("PRESS ENTER:: ");
    getchar();
    printf("......");

    if (fcntl(fd, F_SETLK, &f1) == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("locked..\n");
    printf("PRESS ENTER:: ");
    getchar();
    
    f1.l_type = F_UNLCK;
    
    if (fcntl(fd, F_SETLK, &f1) == -1) {
        perror("fcntl");
        exit(1);
    }
    
    printf("Unlocked\n");

    close(fd);
    return 0;
}

