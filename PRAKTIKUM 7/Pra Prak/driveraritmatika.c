#include <stdio.h>
#include "aritmatika.c"

int main(){
    char input = '9243+*5/-';
    printf("%i\n", eval(input,0));
}