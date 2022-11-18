#include <stdio.h>
#include "list.c"

void tulis (List L){
    printf("[");
    for (int i = 0; i<LastIdx(L); i++){
        printf("%i,",Get(L,i));
    } printf("%i", Get(L,LastIdx(L)));
    printf("]\n");
}
int main(){
    List L1,L2,L3;
    L1 = MakeList();
    L2 = MakeList();
    L3 = MakeList();

    for (int i = 0; i<=5; i++){
        InsertAt(&L1, i, i);
    } InsertAt(&L2, 6, 0);
    InsertAt(&L2, 6, 1);
    tulis(L1);
    tulis(L2);
    L3 = Concat(L1,L2);
    tulis(L3);
    DeleteAt(&L1, 3);
    DeleteAt(&L1, 3);
    tulis(L1);
}