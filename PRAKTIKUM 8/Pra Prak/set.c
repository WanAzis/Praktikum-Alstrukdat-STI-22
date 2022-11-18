// Wan Aufa Azis - 18221001
// 28 Oktober 2022

// ADT Set

#include <stdio.h>
#include "set.h"

#define COUNT(S) (S).Count
#define ELMT(S,i) (S).Elements[i]

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    COUNT(*S)=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return COUNT(S)==Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    return COUNT(S)==MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    if(!IsMember(*S, Elmt)){
        ELMT(*S,COUNT(*S))=Elmt;
        COUNT(*S)++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    boolean found = false;
    int i = 0;
    while (i<COUNT(*S) && !found){
        if(ELMT(*S,i)==Elmt){
            found = true;
        } else{
            i++;
        }
    } // i=S.count or found
    if (found){
        while (i<COUNT(*S)-1){
            ELMT(*S, i)=ELMT(*S, i+1);
            i++;
        } COUNT(*S)--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    boolean found = false;
    int i = 0;
    while (i<COUNT(S) && !found){
        if(ELMT(S,i)==Elmt){
            found= true;
        } else{
            i++;
        }
    } return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */