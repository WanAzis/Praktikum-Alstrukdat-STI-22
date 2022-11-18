#include <stdio.h>
#include "listlinier.h"

int main(){
    List L;
    CreateEmpty(&L);
    if(IsEmpty(L)){
        printf("List masih kosong\n");
    }
    address P = Alokasi(10);
    printf("isi dari hasil alokasi P = %i\n", Info(P));
    Dealokasi(&P);
    InsVFirst(&L,2);
    InsVFirst(&L,1);
    InsVLast(&L,3);
    PrintInfo(L);
    infotype x;
    DelVFirst(&L,&x);
    DelVLast(&L,&x);
    PrintInfo(L);
    InsVFirst(&L,2);
    InsVFirst(&L,1);
    InsVFirst(&L,5);
    InsVFirst(&L,6);
    PrintInfo(L);
    printf("Hasil invers dari list adalah :\n");
    InversList(&L);
    PrintInfo(L);
    List L1, temp;
    CreateEmpty(&L1);
    InsVFirst(&L1,10);
    InsVFirst(&L1,9);
    InsVFirst(&L1,8);
    InsVFirst(&L1,7);

    Konkat1 (&L, &L1, &temp);
    PrintInfo(temp);
    if(IsEmpty(L) && IsEmpty(L1)){
        printf("Keduanya kosong\n");
    }
    DelP(&temp, 5);
    PrintInfo(temp);
}