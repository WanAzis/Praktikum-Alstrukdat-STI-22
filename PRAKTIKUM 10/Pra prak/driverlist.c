/* Driver list sirkuler */

#include <stdio.h>
#include "listsirkuler.h"

int main(){
    List L; CreateEmpty(&L);
    if (IsEmpty(L)){
        printf("list masih kosong\n");
    }
    for (int i = 0; i<5; i++){
        InsVFirst(&L, i);
    } PrintInfo(L); printf("\n");
    DelP(&L, 3);
    printf("ini setelah info 3 dihapus dari list\n"); PrintInfo(L); printf("\n");
    for (int i = 9; i<13; i++){
        InsVLast(&L, i);
    } PrintInfo(L); printf("\n");
    address P9 = Search(L, 9);
    address P20 = Alokasi(20); address P21 = Alokasi(21);
    InsertAfter(&L, P20, P9);
    InsertAfter(&L, P21, P9);
    printf("ini setelah 20 dan 21 dimasukkan setelah 9\n"); PrintInfo(L); printf("\n");
    address P10 = Search(L, 10); address PDel;
    DelAfter(&L, &PDel, P10);
    DelAfter(&L, &PDel, P10);
    printf("ini setelah info setelah 10 dihapus 2 kali\n"); PrintInfo(L); printf("\n");
    InsVFirst(&L, 0); InsVLast(&L, 99);
    PrintInfo(L); printf("\n");
}