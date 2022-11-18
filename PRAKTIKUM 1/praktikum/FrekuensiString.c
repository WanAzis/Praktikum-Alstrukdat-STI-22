/*Wan Aufa Azis - 18221001*/
/*05 September 2022*/

/*PROGRAM FREKUENSI STRING*/
// Menghitung frekuensi tiap angka yang ada dalam inputan string

#include <stdio.h>
#include "string.h"

int main(){
    char str[10];
    int count;
    
    scanf("%s",&str);
    int x = strlen(str);
    for (int i = 0; i<=9; i++){
        count = 0;
        for (int j = 0; j<x; j++){
            if (str[j]==i+'0'){
                count++;
            }
        } printf("%i",count);
    } printf("\n");
    return 0;
}