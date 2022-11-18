/*Wan Aufa Azis - 18221001*/
/*11 September 2022*/

/*PROGRAM JUMLAH BILANGAN*/
/*Menerima input sebuah bilangan lalu menjumlahkan
  setiap digit pada bilangan tersebut*/

#include <stdio.h>

int main()
{
    /*KAMUS*/
    int number,flag=10,sum=0;

    /*ALGORITMA*/
    scanf("%d",&number);
    while (number != 0) {
        sum += number % flag;
        number /= flag;
    }
    printf("%d\n",sum);
    return 0;
}