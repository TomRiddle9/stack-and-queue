#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front,rear,size;
    unsigned capacity;
    int* array;
};

struct Queue* create_queue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity-1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
};

int isfull(struct Queue* queue){
    return queue->size = queue->capacity;
}
int isempty(struct Queue* queue){
    return queue->size =0;
}
int enqueue(struct Queue* queue,int item){

    queue->rear = (queue->rear+1)%(queue->capacity);
    queue->array[queue->rear] = item;
    queue->size = queue->size+1;
}

int dequeue(struct Queue* queue){

    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size = queue->size-1;
    return item;
}
int front(struct Queue* queue){

    return queue->array[queue->front];
}
int rear(struct Queue* queue){

    return queue->array[queue->rear];
}

int main(){
    struct Queue* queue = create_queue(1000);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    printf("\n %d is dequeued from the queue list ",dequeue(queue));
    printf("\n The front end element is -   %d ", front(queue));
    printf("\n The rear end element is -  %d ", rear(queue));

    return 0;
}
