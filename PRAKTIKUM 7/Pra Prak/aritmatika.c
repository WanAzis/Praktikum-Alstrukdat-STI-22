// Wan Aufa Azis - 18221001
// 21 Oktober 2022

// Program Aritmatika Menggunakan ADT Stack

#include <stdio.h>
#include "aritmatika.h"

boolean isOperator(char input){
    return ((input=='+') || (input=='-') || (input=='*') || (input=='/'));
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op){
    int hasil;
    if (op=='+'){
        hasil = angka1 + angka2;
    } else if (op=='-'){
        hasil = angka1 - angka2;
    } else if (op=='*'){
        hasil = angka1 * angka2;
    } else if (op=='/'){
        hasil = angka1 / angka2;
    }
    return hasil;
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length){
    int i=0;
    Stack S;
    CreateEmpty(&S);
    while(input[i]!='\0'){
        if(input[i]>=48 && input[i]<=57){
            Push(&S, input[i]-48);
        } else if(isOperator(input[i])){
            int op1, op2;
            Pop(&S, &op2);
            Pop(&S, &op1);
            Push(&S, hitung(op1, op2, input[i]));
        }
        i++;
    } return InfoTop(S);
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5) */