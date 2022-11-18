// Wan Aufa Azis - 18221001
// 01 Oktober 2022

// IMPLEMENTASI MESIN KARAKTER
// PROGRAM HITUNG KARAKTER

#include <stdio.h>
#include "mesinkarakter.h"

/*Menghitung sebuah karakter dari pita karakter*/
int hitungkarakter(char karakter){
    int count=0;
    START();
    while(!EOP){
        if (GetCC()==karakter){
            count++;
        } ADV();
    } return count;
}