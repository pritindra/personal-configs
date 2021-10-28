#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *handler(void *ptr);

int main() {

    pthread_t thr;
    char *message = "Hello World...";
    int ret;

    ret = pthread_create(&thr, NULL, handler, (void*) message);
    pthread_join(thr, NULL);
    exit(ret);
}

void *handler(void *ptr) {
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
    pthread_exit(NULL);
}
