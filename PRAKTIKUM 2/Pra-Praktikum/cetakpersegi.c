/*Wan Aufa Azis - 18221001*/
/*11 September 2022*/

/*PROGRAM CETAK PERSEGI*/
/*mencetak sebuah persegi berdasarkan masukkan n, 
  dimana panjang dari sisi persegi adalah 2n-1 dan 
  dibentuk dengan pola O dan X secara selang-seling*/

#include <stdio.h>
#define true 1
#define false 0
#define boolean unsigned char

boolean Ganjil(int a) {
    return (a%2) !=0 ;
}

int main()
{
    /*KAMUS*/
    int n,sisi,i,j;

    /*ALGORITMA*/
    scanf("%d",&n);

    sisi = 2*n-1;
    for(i=0;i<sisi;i++) {
        for(j=0;j<sisi;j++) {
            if (Ganjil(i)) {
                if (Ganjil(j)) {
                    printf("O");
                } else { printf("X"); }
            } else { 
                if (Ganjil(j)) {
                    printf("X");
                } else { printf("O"); }
            }
        } printf("\n");
    } return 0;
}