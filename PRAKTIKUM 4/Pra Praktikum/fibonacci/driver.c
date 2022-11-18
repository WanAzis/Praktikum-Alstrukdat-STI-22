#include <stdio.h>
#include "fibonacci.c"

int main(){
    int f1,f2;
    f2 = fibonacci2(5);
    printf("%i\n",f2);
    fibonacci1(5,&f1);
    printf("%i\n",f1);
    
}