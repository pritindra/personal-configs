#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>
    
#define SIZE 100

char req[SIZE], recData[SIZE];
int isGet;
char buffer[SIZE];
FILE *fptr;

int main() {
    int b,sockfd,sin_size,con,n,len;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) > 0)
        printf("socket created ...\n");

    struct sockaddr_in servaddr;              
    struct sockaddr_in clientaddr;

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("10.0.0.1");
    servaddr.sin_port=6006;

    sin_size = sizeof(struct sockaddr_in);
    
    fptr = fopen("test.txt","r");
    fscanf(fptr, "%s", buffer);
    time_t secs = time(NULL);

    sendto(sockfd,(char *) buffer, sizeof(buffer), MSG_CONFIRM, (struct sockaddr *)&servaddr, sizeof(servaddr));
    close(sockfd);
    printf("File uploaded...");
    
    
    return 0;
}



