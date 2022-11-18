#include <stdio.h>
#include "MinMax.h"

int main(){
    List L,tes;
    L = MakeList();
    tes = MakeList();
    InsertFirst(&L,1);
    InsertFirst(&L,2);
    InsertFirst(&L,5);
    InsertFirst(&L,7);
    InsertFirst(&L,0);
    tes = MinMax(L);
    for (int i = FirstIdx(tes); i<=LastIdx(tes); i++){
        printf("%d",tes.A[i]);
    } return 0;
}