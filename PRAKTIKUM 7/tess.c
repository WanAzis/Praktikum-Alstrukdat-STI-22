#include <stdio.h>

#define LEN 5
#define PANJANG 3
typedef int array[LEN];
typedef array matriks[PANJANG];

int main(){
    array satu = {1,2,3,4,5};
    array dua = {2,4,6,8,10};
    array tiga = {3,6,9,12,15};
    matriks coba = {satu, dua, tiga};

    printf("Isi dari array satu: ");
    for (int i = 0; i<LEN; i++){
        printf("%i ", satu[i]);
    } printf("\n");

    printf("Isi dari array dua: ");
    for (int i = 0; i<LEN; i++){
        printf("%i ", dua[i]);
    } printf("\n");

    printf("Isi dari array tiga: ");
    for (int i = 0; i<LEN; i++){
        printf("%i ", tiga[i]);
    } printf("\n");

    printf("Isi dari matriks coba: ");
    for (int i = 0; i<PANJANG; i++){
        for (int j = 0; j<LEN; j++){
            printf("%i ", coba[i][j]);
        } printf("\n");
    } printf("\n");

}