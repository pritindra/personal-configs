#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define SIZE 100
char buffer[SIZE];
FILE *fptr;


void main() {
    int b,sockfd,connfd,sin_size,l,n,len;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) > 0)
        printf("socket created ...\n");

    struct sockaddr_in servaddr;              
    struct sockaddr_in clientaddr;

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("10.0.0.1");
    servaddr.sin_port=6006;

    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) == 0)
        printf("bind success ...");

    len = sizeof(clientaddr);

    sin_size = sizeof(struct sockaddr_in);

    
    n = recvfrom(sockfd,(char *) buffer, SIZE, MSG_WAITALL, (struct sockaddr *) &clientaddr, &len);
    printf("bytes: %d\n", n);
    printf("buffer: %ld\n", sizeof(buffer));

    fptr = fopen("test1.txt", "w");
    fprintf(fptr, "%s", buffer);
    printf("File dwonloaded...");
}



