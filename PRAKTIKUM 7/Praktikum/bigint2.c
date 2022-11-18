// Wan Aufa Azis - 18221001
// 24 Oktober 2022

// Implementasi ADT Stack
// Pengurangan bilangan integer besar menggunakan stack

#include <stdio.h>
#include "stack.h"

int main(){
    Stack s1, s2, ans;
    int val1, val2;
    int carry = 0;
    int check = 0;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&ans);
    char bil1[100], bil2[100];

    scanf("%c", &bil1);
    int i = 0;
    while(bil1[i]!='\0'){
        Push(&s1, bil1[i] - '0');
        i++;
    }

    scanf("%c", &bil1);
    i = 0;
    while(bil1[i]!='\0'){
        Push(&s1, bil1[i] - '0');
        i++;
    }

    while(!IsEmpty(s1) && !IsEmpty(s2)){
        Pop(&s1, &val1);
        Pop(&s2, &val2);
        Push(&ans, (val1+val2+carry) % 10);
        carry = (val1+val2+carry) / 10;
    }

    if(IsEmpty(s1)){
        check = 1;
        while(!IsEmpty(s2)){
            Pop(&s2, &val2);
            Push(&ans, (val2+carry) % 10);
            carry = (val2+carry)/10;
        }
    }
    else{
        while(!IsEmpty(s1)){
            Pop(&s1, &val1);
            Push(&ans, (val1+carry) % 10);
            carry = (val1+carry)/10;
        }
    }

    if(carry!=0){
        Push(&ans, carry);
    }
    if(check==1){
        printf("-");
    }
    while(!IsEmpty(ans)){
        Pop(&ans, &val1);
        printf("%i", val1);
    } printf("\n");
}