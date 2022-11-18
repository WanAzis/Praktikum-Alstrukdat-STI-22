// Wan Aufa Azis - 18221001
// 14 Oktober 2022

// Implementasi ADT Queue Circular

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return Q.HEAD==NIL && Q.TAIL==NIL;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
    return Length(Q)==Q.MaxEl;
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q){
    if (IsEmpty(Q)){
        return 0;
    } else if (Q.TAIL < Q.HEAD){
        return Q.TAIL-Q.HEAD+Q.MaxEl + 1;
    } else {
        return Q.TAIL-Q.HEAD + 1;
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
    return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
    Queue Q;
    Q.Tab = (ElType *) malloc (Max * sizeof(ElType));
    Q.HEAD=NIL;
    Q.TAIL=NIL;
    if (Q.Tab==NULL){ //Alokasi gagal
        Q.MaxEl=0;
    } else {
        Q.MaxEl=Max;
    } return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
    free((*Q).Tab);
    (*Q).MaxEl=0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
    if (IsEmpty(*Q)){
        (*Q).HEAD=0;
        (*Q).TAIL=0;
    } else {
        (*Q).TAIL++;
        (*Q).TAIL%=(*Q).MaxEl;
    } (*Q).Tab[(*Q).TAIL]=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q){
    ElType val = Front(*Q);
    if ((*Q).HEAD==(*Q).TAIL){
        (*Q).HEAD=NIL;
        (*Q).TAIL=NIL;
    } else {
        (*Q).HEAD++;
        (*Q).HEAD%=(*Q).MaxEl;
    }
    return val;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD
        HEAD "maju" dengan mekanisme circular buffer
        Q mungkin kosong */
ElType Front (Queue Q){
    return Q.Tab[Q.HEAD];
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD
        Q pasti tetap tidak kosong */