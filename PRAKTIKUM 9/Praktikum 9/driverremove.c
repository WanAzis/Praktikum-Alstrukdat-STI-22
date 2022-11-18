#include <stdio.h>
#include "removeDuplicate.h"

int main(){
    List L; CreateEmpty(&L);
    InsVFirst(&L,7);
    InsVFirst(&L,6);
    InsVFirst(&L,6);
    InsVFirst(&L,5);
    InsVFirst(&L,4);
    InsVFirst(&L,3);
    InsVFirst(&L,2);
    InsVFirst(&L,2);
    InsVFirst(&L,1);
    InsVFirst(&L,1);
    PrintInfo(L); printf("\n");
    L = removeDuplicate(L);
    PrintInfo(L);
}