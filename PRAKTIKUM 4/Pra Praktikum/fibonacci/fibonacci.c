// Wan Aufa Azis - 18221001
// 25 September 2022

// PROGRAM BILANGAN FIBONACCI

#include <stdio.h>
#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
    (*result) = fibonacci2(n);
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
    if (n==0 || n==1) {
        return 1;
    } else {return fibonacci2(n-2) + fibonacci2(n-1);}
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
    int i=0;
    for (i; i<=n; i++){
        result[i] = fibonacci2(i);
    } // *result = arr;
}