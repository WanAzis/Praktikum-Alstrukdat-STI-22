// Wan Aufa Azis - 18221001
// 26 September 2022

// PROGRAM MIN MAX BILANGAN

#include <stdio.h>
#include "MinMax.h"

/* Mencari elemen maksimum dalam list L */
ElType Max(List L){
    ElType maks=Get(L,FirstIdx(L));
    for (IdxType i = FirstIdx(L)+1; i<=LastIdx(L); i++){
        if (Get(L,i)>maks){
            maks = Get(L,i);
        }
    } return maks;
    // IdxType j = FirstIdx(L);
    // while (Get(L,j)!=maks){
    //     j++;
    // } return j;
}
/* Mencari elemen minimum dalam list L */
ElType Min(List L){
    ElType mins=Get(L,FirstIdx(L));
    for (IdxType i = FirstIdx(L)+1; i<=LastIdx(L); i++){
        if (Get(L,i)<mins){
            mins = Get(L,i);
        }
    } return mins;
    // IdxType j = FirstIdx(L);
    // while (Get(L,j)!=mins){
    //     j++;
    // } return j;
}
/* Mencari indeks elemen X dalam list L */
IdxType cari(List L, ElType X){
    IdxType i = FirstIdx(L);
    while (Get(L,i)!=X){
        i++;
    } return i;
}
List MinMax(List L){
    ElType mins, maks;
    mins = Min(L);
    DeleteAt(&L, cari(L,mins));
    InsertLast(&L,mins);
    maks = Max(L);
    DeleteAt(&L, cari(L,maks));
    InsertLast(&L,maks);
    return L;
}