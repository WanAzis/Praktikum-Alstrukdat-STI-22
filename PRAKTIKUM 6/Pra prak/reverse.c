// Wan Aufa Azis - 18221001
// 14 Oktober 2022

// Implementasi ADT Queue

#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
    int loop = Length(*q1);
    for (int i = 0; i<loop; i++){
        Push(q2, Pop(q1));
        for (int j=Length(*q2)-1; j>0; j--){
            ElType temp = (*q2).Tab[j];
            (*q2).Tab[j]=(*q2).Tab[j-1];
            (*q2).Tab[j-1]=temp;
        }
    }
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik