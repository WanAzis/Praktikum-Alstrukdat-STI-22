#include <stdio.h>
#include "stack.h"

void strtostack (char *s, Stack* hasil){
    int i = 0;
    while (s[i]!='\0'){
        Push(hasil, s[i]-'0');
        i++;
    }
}
/* Memasukkan setiap digit string kedalam stack of integer */

int length(Stack s){
    return Top(s)+1;
}
/* Mengembalikan panjang atau banyak elemen dari stack s */

boolean isBiggerThan(Stack s1, Stack s2){
    if(length(s1)>length(s2)){
        return true;
    } else if (length(s1)<length(s2)){
        return false;
    } else {
        boolean found=true;
        int i = 0;
        while (i<length(s1)){
            if (s1.T[i]==s2.T[i]){
                i++;
            } else {
                if (s1.T[i]>s2.T[i]){
                    return true;
                } else {
                    return false;
                }
            }
        } return found;
    }
}
/* Mengembalikan true jika stack s1 lebih besar dari pada stack s2. False jika sebaliknya */

boolean isEqual(Stack s1, Stack s2){
    if (length(s1)==length(s2)){
        boolean found = true;
        int i = 0;
        while (i<length(s1) && found){
            if (s1.T[i]!=s2.T[i]){
                found = false;
            } else {
                i++;
            }
        } return found;
    } else {
        return false;
    }
}
/* Mengembalikan true jika stack s1 sama besar dengan stack s2 */

void substack(Stack s1, Stack s2, Stack* hasil){
    infotype a,b;
    while (!IsEmpty(s2)){
        Pop(&s1,&a); Pop(&s2,&b);
        if (a<b){
            a+=10; InfoTop(s1)--;
        } Push(hasil,a-b);
    }
    if (!IsEmpty(s1)){
        while (!IsEmpty(s1)){
            Pop(&s1,&a); Push(hasil,a);
        }
    }
}
/* Prosedur mengurangkan s1 dengan s2 lalu menaruh hasilnya pada stack hasil. 
   stack s1 tidak sama dan dipastikan lebih besar dari s2 */

void printStack(Stack s){
    infotype a;
    while (!IsEmpty(s)){
        Pop(&s,&a); printf("%i",a);
    } printf("\n");
}
/* Menuliskan isi stack ke layar */

void deleteNul(Stack* s){
    infotype a;
    while(InfoTop(*s)==0){
        Pop(s,&a);
    }
}

int main(){
    int hasil;
    Stack s1, s2, ans; char bil1[100], bil2[100];
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&ans);

    // Membaca input
    scanf("%s", &bil1); strtostack(bil1,&s1);
    scanf("%s", &bil2); strtostack(bil2,&s2);

    // Membandingkan bigint dan proses mengurangi
    if(isEqual(s1,s2)){
        hasil = 0;
        printf("%i", hasil);
    } else {
        if(isBiggerThan(s1,s2)){
            substack(s1,s2,&ans);
        } else {
            substack(s2,s1,&ans);
        }
    }
    // Print hasil
    if (!isBiggerThan(s1,s2)){
        printf("-");
    } deleteNul(&ans);
    printStack(ans);
    
    return 0;
}