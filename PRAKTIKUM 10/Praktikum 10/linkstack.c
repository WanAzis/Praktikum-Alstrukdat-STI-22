// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 14 November 2022
// Topik        : ADT List Linier
// Deskripsi    : Implementasi Stack dengan list linier

#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X){
    Node *alok = (Node*) malloc (sizeof(Node));
    if (alok!=Nil){
        Info(alok)=X; Next(alok)=Nil;
    } *P = alok;
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S){
    return Top(S)==Nil;
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty(Stack *S){
    Top(*S)=Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push(Stack *S, ElType X){
    address P; Alokasi(&P, X);
    if (P!=Nil){
        if(IsEmpty(*S)){
            Top(*S)=P;
        } else {
            Next(P)=Top(*S); Top(*S)=P;
        }
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop(Stack *S, ElType *X){
    address P = Top(*S);
    *X = Info(P);
    Top(*S)=Next(Top(*S));
    Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */