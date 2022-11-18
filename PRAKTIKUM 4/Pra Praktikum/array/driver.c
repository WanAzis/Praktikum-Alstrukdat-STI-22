#include <stdio.h>
#include "array.h"
#include "array.c"

int main(){
    int i,v=1,maks,mins;
    TabInt T,Tcop,T3;
    MakeEmpty(&T);
    for (i=IdxMin; i<=5; i++){
        SetEl(&T,i,v); v++;
    } SetEl(&T,6,99);
    SetNeff(&T,6);
    TulisIsi(T);
    maks = IdxMaxTab(T);
    mins = IdxMinTab(T);
    printf("%i %i\n",maks,mins);
    SetTab(T,&Tcop);
    TulisIsi(Tcop);
    T3 = PlusTab(T,Tcop);
    TulisIsi(T3);
}