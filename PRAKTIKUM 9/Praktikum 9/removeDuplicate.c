// Wan Aufa Azis - 18221001
// 07 November 2022
// ADT List Linier

#include <stdio.h>
#include "removeDuplicate.h"

List removeDuplicate(List l){
    address P = Next(First(l));
    address prec = First(l);
    while(P!=Nil){
        if (Info(P)==Info(prec)){
            // address del = P;
            Next(prec)=Next(P);
            P = Next(P);
            
        } else {
            prec = P;
            P = Next(P);
        }
    } return l;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/