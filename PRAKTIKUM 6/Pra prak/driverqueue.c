#include <stdio.h>
#include "queuemelingkar.c"

int main(){
    Queue q; ElType val;
    CreateQueue(&q);
    if (isEmpty(q)){
        printf("kosong\n");
    } else {
        printf("Berisi\n");
    } displayQueue(q);
    if (isFull(q)){
        printf("Penuh\n");
    } else {
        printf("masih ada ruang\n");
    }
    for (int i = 0; i<CAPACITY; i++){
        enqueue(&q, i);
    }
    if (isFull(q)){
        printf("Penuh\n");
    } else {
        printf("masih ada ruang\n");
    }
    for (int j = 0; j<=10; j++){
        dequeue(&q,&val);
    }
    printf("posisi tail ada di: %i\n", IDX_TAIL(q));
    printf("posisi head ada di: %i\n", IDX_HEAD(q));
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("posisi tail ada di: %i\n", IDX_TAIL(q));
    for (int k = 0; k<=80; k++){
        dequeue(&q,&val);
    }
    printf("posisi head ada di: %i\n", IDX_HEAD(q));
    displayQueue(q);
}