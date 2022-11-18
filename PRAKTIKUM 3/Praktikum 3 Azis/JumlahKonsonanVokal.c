// Wan Aufa Azis - 18221001
// 19 September 2022

// PROGRAM MENGHITUNG JUMLAH HURUF KONSONAN DAN VOKAL DALAM SUATU KALIMAT

#include <stdio.h>
#include "jumlahkonsonanvokal.h"
#define boolean_H
#define true 1
#define false 0
#define boolean unsigned char

boolean isAlphabet (char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}
void jumlahKonsonanVokal(char*c, int*k, int*v){
    // int konso, voc;
    while (*c != '\0'){
        if(isAlphabet(*c)){
            if((*c == 'a' || *c == 'A') ||
            (*c == 'i' || *c == 'I') ||
            (*c == 'u' || *c == 'U') ||
            (*c == 'e' || *c == 'E') ||
            (*c == 'o' || *c == 'O')){
                (*v)++;
            } else {(*k)++;}
        } c++;
    }
}
