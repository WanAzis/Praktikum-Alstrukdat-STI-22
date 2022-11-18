/*Wan Aufa Azis - 18221001*/
/*12 September 2022*/

/*PROGRAM BALIK INTEGER*/
/*Menerima satu bilangan integer positif lalu menampilkan output
  integer tersebut dengan tiap digitnya sudah dibalik*/

#include <stdio.h>

int main()
{
    /*KAMUS*/
    int n,digit,flag=10;
    /*ALGORITMA*/
    scanf("%d",&n);
    while (n!=0) {
        digit = n%10;
        printf("%d",digit);
        n/=flag;
    } printf("\n");
    return 0;
}