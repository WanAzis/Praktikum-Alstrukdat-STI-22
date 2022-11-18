/*Nama     : Wan Aufa Azis*/
/*NIM      : 18221001*/
/*Tanggal  : 04 September 2022*/
/*Deskripsi: Konversi detik kedalam jam menit dan detik*/

#include <stdio.h>

int main()
{
    int S,jam,menit,detik,Temp;

    scanf("%d",&S); Temp=S;
    jam = Temp/3600;
    Temp = Temp % 3600;
    menit = Temp/60;
    Temp = Temp % 60;
    detik = Temp;
    
    printf("%d detik = %d jam %d menit %d detik\n",S,jam,menit,detik);
    return 0;

}