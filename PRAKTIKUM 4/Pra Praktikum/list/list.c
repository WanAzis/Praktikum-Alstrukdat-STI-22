// Wan Aufa Azis - 18221001
// 25 September 2022

// IMPLEMENTASI ADT LIST

#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List L;
    for (int i = 0; i<MaxEl; i++){
        Set(&L, i, Mark);
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
// [5,4,7,mark,mark]
boolean IsEmpty(List L){
    return Get(L,FirstIdx(L))==Mark;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    if (IsEmpty(L)){
        return 0;
    } else {
        IdxType i = 0;
        while (i<MaxEl && Get(L,i)!=Mark){
        i++;
        }
        return i;
    }
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    int i = 0;
    return i;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return Length(L)-1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return (i>=0) && (i<MaxEl);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return (i>=FirstIdx(L)) && (i<=LastIdx(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    int i = FirstIdx(L);
    boolean found = false;
    while (i<LastIdx(L) && Get(L,i)!=X){
        i++;
        // if (found true)
    } if (Get(L,i)==X){
        found = true;
        // return true;
    } return found;
    // else {return false;}
    // for (i; i<=LastIdx(L); i++){
    //     if (Get(L,i)==X){
    //         return true;
    //     }
    // } return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    InsertAt(L,X,FirstIdx(*L));
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. 
    [0,1,2,0,3,4,5] */

void InsertAt(List *L, ElType X, IdxType i){
    int j = LastIdx(*L);
    for (j; j>=i; j--){
        // (*L).A[j+1] =  (*L).A[j];
        Set(L, j+1, Get(*L, j));
    } Set(L,i,X);
    // (*L).A[i]=X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    // Set(L,LastIdx(*L)+1,X);
    InsertAt(L,X,LastIdx(*L)+1);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    DeleteAt(L, FirstIdx(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
// [0,1,2,0,4,5]
void DeleteAt(List *L, IdxType i){
    for (i; i<=LastIdx(*L); i++){
        Set(L, i, Get(*L, i+1));
    } 
    // Set(L, Length(*L)-1, Mark);
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    DeleteAt(L, LastIdx(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2){
    List LConc;
    int i=FirstIdx(L1),j=FirstIdx(L2);

    LConc = MakeList();
    while (i<=LastIdx(L1)){
        Set(&LConc, i, Get(L1,i));
        i++;
    }
    while (j<=LastIdx(L2)){
        Set(&LConc, i, Get(L2,j));
        i++; j++;
    } return LConc;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; 
            L2 : [3, 4]; 
            Mengembalikan [1, 2, 3, 4] */