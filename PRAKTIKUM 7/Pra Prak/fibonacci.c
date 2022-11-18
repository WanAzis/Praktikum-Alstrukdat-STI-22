#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main(){
    infotype c1, c2, chasil;
    Stack S;
    int x;

    CreateEmpty(&S);
    scanf("%i", &x);

    for(int i = 1; i<=x; i++){
        if(i==1){
            Push(&S, 0);
        } else if(i==2){
            Push(&S, 1);
        } else {
            Pop(&S, &c2);
            Pop(&S, &c1);
            chasil=c1 + c2;
            Push(&S, c2);
            Push(&S, chasil);
        }
    }
    printf("%i\n", InfoTop(S));
}