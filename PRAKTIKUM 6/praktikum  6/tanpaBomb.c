// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 17 Oktober 2022
// Topik        : ADT Queue
// Deskripsi    : 

#include <stdio.h>
#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb){
    Queue q;
    CreateQueue(&q);
    ElType loop = length(queue);
    for (int i = 0; i<loop; i++){
        ElType val;
        dequeue(&queue, &val);
        if (val!=bomb){
            enqueue(&q, val);
        }
    } return q;

}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/