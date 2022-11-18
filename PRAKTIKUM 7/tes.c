#include <stdio.h>
#include "boolean.h"

int main(){
    boolean flag = false;
    char operator[] = "+-*/^";
    char kar;
    printf("Masukkan karater: ");
    scanf("%c", &kar);
    for (int i = 0; i<5; i++){
        if(kar==operator[i]){
            flag=true;
        }
    }
    // flag = (kar=='+') || (kar=='-') || (kar=='*') || (kar=='/') || (kar=='^');
    if (flag){
        printf("Karakter merupakan operator\n");
    } else {
        printf("Karakter bukan merupakan operator\n");
    }
    return 0;
}