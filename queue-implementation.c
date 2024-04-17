#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

struct Queue {
    int head;
    int tail;
    int capacity;
    int* data;
};

Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = size+1;
    queue->data = (int*) malloc((size+1) * sizeof(int));
    return queue;
}

void destroyQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int queueSize(Queue* queue) {
    return (queue->tail - queue->head + queue->capacity) % queue->capacity; 
}

int queueIsFull(Queue* queue) {
    if ((queue->tail + 1) % queue->capacity  == queue->head)
        return 1;
    else
        return 0;
}

int queueIsEmpty (Queue* queue) {
    if (queue->head == queue->tail)
        return 1;
    else
        return 0;
}

int queuePush(int value, Queue* queue) {
    if (queueIsFull(queue))
        return 0;
    else {
        queue->tail = (queue->tail + 1) % queue->capacity;
        queue->data[queue->tail] = value;
        return 1;
    }
}

int queuePop(Queue* queue, int* value) {
    if (queueIsEmpty(queue))
        return 0;
    else {
        queue->head = (queue->head + 1 ) % queue->capacity;
        *value = queue->data[queue->head]; 
        return 1;
    }
}


int main() {
    Queue* queue = createQueue(5);
    
    for (int i = 0; i < 6; i++) {
        if(queuePush(i, queue))
            printf("pushed %d with success!\n", i);
        else
            printf("pushed %d with FAILURE!\n", i);
    }

    int *value = malloc(sizeof(int));

    for (int i = 0; i < 6; i++) {
        if(queuePop(queue, value))
            printf("popped %d with success!\n", *value);
        else
            printf("failure to pop at index: %d\n", i);
    }

    destroyQueue(queue);

    return 0;
}

