// Wan Aufa Azis - 18221001
// 28 Oktober 2022

// ADT Map

#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
    (*M).Count=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M){
    return M.Count==Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
    return M.Count==MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
    boolean found = false;
    int i = 0;
    while(i<M.Count && !found){
        if(M.Elements[i].Key==k){
            found = true;
        } else {
            i++;
        }
    }
    if (found){
        return M.Elements[i].Value;
    } else {return Undefined;}
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v){
    if(!IsMember(*M, k)){
        (*M).Elements[(*M).Count].Key=k;
        (*M).Elements[(*M).Count].Value=v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
    boolean found = false;
    int i = 0;
    while (i<(*M).Count && !found){
        if((*M).Elements[i].Key==k){
            found = true;
        } else{
            i++;
        }
    }
    if (found){
        while (i<(*M).Count-1){
            (*M).Elements[i]=(*M).Elements[i+1];
            i++;
        } (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
    boolean found = false;
    int i = 0;
    while (i<M.Count && !found){
        if(M.Elements[i].Key==k){
            found= true;
        } else{
            i++;
        }
    } return found;
}
/* Mengembalikan true jika k adalah member dari M */