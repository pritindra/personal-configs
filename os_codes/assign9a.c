// http://tharikasblogs.blogspot.com/p/how-to-write-your-own-malloc-and-free.html

#include <stdio.h>
#include <unistd.h>

#define N 10
int main() {
    int i, array[2000];
    printf("\nEnter N numbers: ");
    array = MyOwnMalloc(sizeof(int) * N);
    for (i=0;i<N;i++) 
        scanf("%d", &array[i]);
    printf("\n The numbers are: \n");
    for (i=0;i<N;i++)
        printf("%d", array[i]);
    return 0;
}


struct chunk {
    int size;
    int free;
    struct chunk *next;
};

void initialize() {
    flist->size=2000-sizeof(struct chunk);
    flist->free=1;
    flist->next=NULL;
}

void split(struct chunk *fitting_slot,size_t size) {
    struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block));
    new->size=(fitting_slot->size)-size-sizeof(struct chunk);
    new->free=1;
    new->next=fitting_slot->next;
    fitting_slot->size=size;
    fitting_slot->free=0;
    fitting_slot->next=new
}

void MyOwnMalloc (size_t N) {
    
    if (size == 0)
        return NULL;
    struct chunk *flist = (void*)array;
    struct chunk *prev,*curr;
    
    void *result;

    if(!(flist->size)) {
        initialize();
        printf("Memory initialized\n");
    }
    curr = flist;
    while((((curr->size)<N)||((curr->free)==0))&&(curr->next!=NULL)) {
        prev = curr;
        curr=curr->next;
        printf("one block checked\n");
    }
    if((curr->size)==N) {
        curr->free=0;
        result=(void*)(++curr);
        printf("exact fitting block llocated\n");
        return result;
    }
    else if((curr->size)>(N+sizeof(struct chunk))) {
        spit(curr,N);
        result = (void*)(++curr);
        printf("Fitting block allocated with a split\n");
        return result;
    }
    else {
        result=NULL;
        printf("No suffiecient memory\n");
        return result;
    }
}

void merge(){
    struct chunk *curr,*prev;
    curr=flist;
    while((curr->next)!=NULL){
        if((curr->free) && (curr->next->free)){
            curr->size+=(curr->next->size)+sizeof(struct chunk);
            curr->next=curr->next->next;
         } 
        prev=curr;
        curr=curr->next;
     }
}

void MyOwnFree(void* ptr) {
    if(((void*)array<=ptr)&&(ptr<=(void*)(array+2000))){
        struct block* curr=ptr;
        --curr;
        curr->free=1;
        merge();
    }
    else 
        printf("Provide valid pointer allocated;")
} 


