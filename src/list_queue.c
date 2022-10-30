#include "list_queue.h"

void init_queue(queue *q) {
    /*initialising queue by making it empty*/
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int empty(queue *q) {
    /*If the size is greater than 0 the list is not empty and it returns false*/
    if (q->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(queue *q, int x) {
    /*Allocating memory for the new node*/
    qnode *newRear = (qnode *)malloc(sizeof(qnode));
    /*Setting the data, and pointing it to NULL (as pointing to NULL makes sure
     * its rear)*/
    newRear->data = x;
    newRear->next = NULL;

    if (empty(q) == 1) {
        /*If the list is empty, the new node becomes the front and rear*/
        q->front = newRear;
    } else {
        /*If it isn't empty the new node is the new rear*/
        q->rear->next = newRear;
    }
    /*counting up size and assigning the rear to the new rear (hvis det giver
     * mening...)*/
    q->rear = newRear;
    ++q->size;
}

int dequeue(queue *q) {
    /*Storing the data in a temp variable*/
    int t = q->front->data;
    /*creating a pointer to the front node, so we can make sure to free it*/
    qnode *oldFront = q->front;
    /*the new front becomes the next in line*/
    q->front = q->front->next;
    /*Freeing the original front*/
    free(oldFront);
    --q->size;
    return t;
}
