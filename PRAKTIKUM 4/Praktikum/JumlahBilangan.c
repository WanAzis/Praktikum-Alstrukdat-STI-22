// Wan Aufa Azis - 18221001
// 26 September 2022

// PROGRAM 

#include <stdio.h>
#include <stdlib.h>

int main (){
    long n, q, l, r, sum;

    scanf("%li",&n);
    int *arr = (int *) malloc (n * sizeof(int));

    for (int i = 0; i<n; i++){
        scanf("%i",&arr[i]);
    }

    scanf("%ld",&q);
    while (q--){
        sum = 0;
        scanf("%ld %ld",&l,&r);
        for (l; l<=r; l++){
            sum += arr[(l-1) % n];
        }
        printf("%ld\n",sum);
    } free(arr);
    return 0;
}