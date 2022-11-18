/*Wan Aufa Azis - 18221001*/
/*12 September 2022*/

/*PROGRAM BILANGAN CANTIK*/
/*Menerima input sebanyak N bilangan, lalu di setiap bilangan
  menentukan berapa jumlah dari bilangan cantik*/
/*Bilangan termasuk dalam kategori bilangan cantik apabila
  terdapat angka 7 atau bilangan dapat dibagi dengan 7*/ 

#include <stdio.h>
#define true 1
#define false 0
#define boolean unsigned char

boolean Cantik(long int a) {
    // KAMUS LOKAL

    // ALGORITMA
    if (a % 7 == 0) {
        return true;
    } 
    while (a != 0) 
    {
        if (a % 10 == 7) {return true;}
        a /= 10;
    } return false;
}

int main()
{
    /*KAMUS*/
    int N,i=1;
    long int M,sum,flag;
    /*ALGORITMA*/
    scanf("%d",&N);
    for (i;i<=N;i++) {
        scanf("%ld",&M);
        flag=1;
        sum=0;
        while (flag<=M) {
            if (Cantik(flag)) {
                sum+=flag;
            } flag+=1;
        } printf("%ld\n",sum);
    }
    return 0;
}