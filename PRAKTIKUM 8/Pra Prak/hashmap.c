// Wan Aufa Azis - 18221001
// 28 Oktober 2022

// ADT Hash

#include <stdio.h>
#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
    for(int i = 0; i<MaxEl; i++){
        (*M).Elements[i].Key=Undefined;
        (*M).Elements[i].Value=Undefined;
    } (*M).Count=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    return K%MaxEl;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
    boolean found = false;
    int i = 0;
    while(i<MaxEl && !found){
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

void Insert(HashMap *M, keytype k, valuetype v){
    int i = 0;
    boolean found = false;
    while(i<MaxEl && !found){
        if((*M).Elements[i].Key==k){
            found=true;
        } else {
            i++;
        }
    }
    if(!found){
        int idx = Hash(k);
        if((*M).Elements[idx].Key==Undefined){
            (*M).Elements[idx].Key=k;
            (*M).Elements[idx].Value=v;
        } else{
            while(!found){
                if((*M).Elements[idx].Key==Undefined){
                    found = true;
                } else{
                    idx = (idx+1) % MaxEl;
                }
            }
            (*M).Elements[idx].Key=k;
            (*M).Elements[idx].Value=v;
        } (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */