#include <stdio.h>
#include "point.c"
#include "garis.c"

int main(){
    POINT P1 = MakePOINT(1,2);
    POINT P2 = MakePOINT(3,4);
    GARIS G1,G2;
    MakeGARIS(P1,P2,&G1);
    printf("Garis G1 adalah:\n");
    TulisGARIS(G1);
    printf("panjang garis G1: %f\n",PanjangGARIS(G1));
    BacaGARIS(&G2);
    printf("Garis G2 adalah:\n");
    TulisGARIS(G2);
    printf("panjang garis G2: %f\n",PanjangGARIS(G2));
    return 0;
}