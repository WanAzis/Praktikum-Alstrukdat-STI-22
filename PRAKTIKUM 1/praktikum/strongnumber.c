/*Wan Aufa Azis - 18221001*/
/*05 September 2022*/

/*PROGRAM STRONG NUMBER*/
/*Menentukan apakah sebuah bilangan merupakan strong number atau bukan.
  Bilangan yang merupakan strong number adalah ketika jumlah faktorial tiap digitnya sama
  dengan angkanya*/

#include <stdio.h>

int faktorial (int a)
{
    /* KAMUS LOKAL */
    int n;

    /* ALGORITMA */
    n = 1;
    while (a!=0) {
        n *= a--;
    } return n;
}

int main()
{
    /*KAMUS*/
    int number,flag,Temp,jumlah,cek;

    /*ALGORITMA*/
    scanf("%d",&number);
    cek = number;
    flag = 10;
    jumlah = 0;
    while(number != 0) {
        Temp = number % flag;
        number /= flag;
        jumlah += faktorial(Temp);
    }
    if (jumlah == cek) {
        printf("Y\n");
    } else { printf("N\n"); }
    return 0;
}