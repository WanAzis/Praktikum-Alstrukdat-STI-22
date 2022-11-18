// Wan Aufa Azis - 18221001
// 07 November 2022
// ADT List Linier

#include <stdio.h>
#include "listlinier.h"

int main(){
    int N, Q, val;
    scanf("%i", &N);
    List L;
    CreateEmpty(&L);
    for (int i = 1; i<=N; i++){
        InsVLast(&L,i);
    }
    scanf("%i", &Q);
    while(Q--){
        scanf("%i", &val);
        address P = Search(L,val);
        if (P!=Nil){
            DelP(&L,val);
            InsVFirst(&L,val);
            printf("hit "); PrintInfo(L);
        }
        else {
            DelLast(&L,&P);
            InsVFirst(&L,val);
            printf("miss "); PrintInfo(L);
        } 
        printf("\n");
    }
}

