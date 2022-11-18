// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 14 November 2022
// Topik        : ADT List Linier
// Deskripsi    : List Linier dengan elemen dummy

#include <stdio.h>
#include <stdlib.h>
#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L){
    return First(L)==Last(L);
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L){
    address dummy = Alokasi(0);
    First(*L)=dummy; Last(*L)=dummy;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X){
    Node *P = (Node*) malloc (sizeof(Node));
    if (P!=Nil){
        Info(P)=X; Next(P)=Nil;
    } return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X){
    address P = Nil;
    if (!IsEmpty(L)){
        address loc = First(L); boolean found = false;
        while (loc!=Last(L) && !found){
            if (Info(loc)==X){
                P = loc; found = true;
            } else {
                loc = Next(loc);
            }
        }
    } return P;
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X){
    address P = Alokasi(X);
    if(P!=Nil){
        Next(P)=First(*L); First(*L)=P;
    }
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X){
    address P = Alokasi(X);
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        address prev = First(*L);
        while (Next(prev)!=Last(*L)){
            prev = Next(prev);
        }
        Next(P)=Last(*L); Next(prev)=P;
    }
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X){
    address P = First(*L); *X = Info(P);
    if (Next(First(*L))==Last(*L)){
        MakeEmpty(L);
    } else {
        First(*L)=Next(First(*L));
    } Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X){
    address P = First(*L); 
    while (Next(P)!=Last(*L)){
        P = Next(P);
    } *X = Info(P);
    if (Next(First(*L))==Last(*L)){
        MakeEmpty(L);
    } else {
        address loc = First(*L);
        while (Next(loc)!=P){
            loc = Next(loc);
        }
        Next(loc)=Last(*L);
    } Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */