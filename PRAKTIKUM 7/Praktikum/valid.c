// Wan Aufa Azis - 18221001
// 26 Oktober 2022

// Implementasi ADT Stack

#include <stdio.h>
#include "valid.h"

Stack validParantheses(char* input, int length){
    Stack s;
    CreateEmpty(&s);

    for (int i = 0; i<length-1; i++){
        if ((input[i]=='(' && input[i+1]==')') ||
            (input[i]=='{' && input[i+1]=='}') ||
            (input[i]=='[' && input[i+1]==']')){
                Push(&s, input[i]);
                Push(&s, input[i+1]);
        }
    } return s;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/