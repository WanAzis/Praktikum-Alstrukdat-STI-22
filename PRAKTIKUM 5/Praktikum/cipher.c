// Nama             : Wan Aufa Azis
// NIM              : 18221001
// Tanggal          : 03 Oktober 2022
// Topik Praktikum  : Mesin Karakter & Mesin Kata
// Deskripsi        : Melakukan penggeseran sebanyak n huruf pada setiap karakter

#include <stdio.h>
#include "mesinkata.h"

int main(){
    STARTWORD();
    int key = currentWord.Length;
    while (!isEndWord()){
        for (int i = 0; i<currentWord.Length; i++){
            char cipher = (currentWord.TabWord[i] - 'A' + key) % 26 + 'A';
            printf("%c", cipher);
        }
        ADVWORD();
        if(!isEndWord()){
            printf(" ");
        }
    } printf(".\n");
    return 0;
}


