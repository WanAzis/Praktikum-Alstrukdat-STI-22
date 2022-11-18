// Wan Aufa Azis - 18221001
// 18 September 2022

// PROGRAM PANJANG STRING
#include <stdio.h>
#include "panjangstring.h"

int panjangString (char* a)
{
    // KAMUS LOKAL
    int i; 
    // ALGORITMA
    i = 0;
    while (*a!='\0') {
        i++;
        a++;
    } return i;
}