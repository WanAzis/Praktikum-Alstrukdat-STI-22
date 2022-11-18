#include <stdio.h>
#include "OddEvenList.h"

int main(){
    List L1,L2,L3;
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);
    InsVFirst(&L1,3);
    InsVFirst(&L1,4);
    InsVFirst(&L1,5);
    InsVFirst(&L1,1);
    InsVFirst(&L1,0);
    PrintInfo(L1); printf("\n");
    OddEvenList(L1,&L2,&L3);
    PrintInfo(L2); printf("\n");
    PrintInfo(L3); printf("\n");
    

}