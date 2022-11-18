// Wan Aufa Azis - 18221001
// 21 Oktober 2022

// Program Palindrom Menggunakan ADT Stack

#include <stdio.h>
#include "stack.h"

int main(){
    Stack S;
    CreateEmpty(&S);
    infotype val;
    scanf("%i", &val);
    while (val!=0){
        Push(&S, val);
        scanf("%i", &val);
    } // val = 0

    if (IsEmpty(S)){
        printf("Stack kosong\n");
    } else {
        int i = 0;
        int j = Top(S);
        boolean found = false;
        while ((i<=Top(S)) && !found){
            if (S.T[i] != S.T[j]){
                found = true;
            } else {
                i++; j--;
            }
        }
        if (!found){
            printf("Palindrom\n");
        } else {printf("Bukan Palindrom\n");}
    }
}