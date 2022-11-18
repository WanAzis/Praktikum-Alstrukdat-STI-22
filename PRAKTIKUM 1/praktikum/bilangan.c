/*Wan Aufa Azis - 18221001*/
/*05 September 2022*/

/*PROGRAM BILANGAN SUBSET GENAP*/
/*Menentukan apakah sebuah bilangan merupakan bilangan subset genap atau bukan*/

#include <stdio.h>

int main()
{
    /*KAMUS*/
    int n;

    /*ALGORITMA*/
    scanf("%d",&n);
    
    if ((n % 2 == 0) && (n != 2)) {
        printf("Ya\n");
    } else { printf("Tidak\n"); }
    return 0;
}