// Wan Aufa Azis - 18221001
// 06 November 2022
// Implementasi ADT List Linier

#include "OddEvenList.h"

/* Mengurutkan sebuah list dengan terurut membesar pada infonya */
void SortDesc(List *L){

}

void OddEvenList(List L, List *Odd, List *Even){
    // CreateEmpty(Odd); CreateEmpty(Even);
    address P = First(L);
    while(P!=Nil){
        if (Info(P)%2==0 || Info(P)==0){
            if(IsEmpty(*Even)){
                InsVFirst(Even,Info(P));
            } else {
                address insert = Alokasi(Info(P));
                address loc = First(*Even);
                if (Info(P)<=Info(First(*Even))){
                    InsertFirst(Even,insert);
                } else  {
                    while(Info(P)>Info(Next(loc))){
                        loc = Next(loc);
                    } InsertAfter(Even,insert,loc);
                }
            }
        }
        else {
            if(IsEmpty(*Odd)){
                InsVFirst(Odd,Info(P));
            } else {
                address insert = Alokasi(Info(P));
                address loc = First(*Odd);
                if (Info(P)<=Info(First(*Odd))){
                    InsertFirst(Odd,insert);
                } else  {
                    while(Info(P)>Info(Next(loc))){
                        loc = Next(loc);
                    } InsertAfter(Odd,insert,loc);
                }
            }
        } P = Next(P);
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/