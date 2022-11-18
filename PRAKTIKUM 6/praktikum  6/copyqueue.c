// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 17 Oktober 2022
// Topik        : ADT Queue
// Deskripsi    : Menyalin isi dari queueinput ke queue output

#include <stdio.h>
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput){
    ElType loop = length(*queueInput);
    for (int i = 0; i<loop; i++){
        ElType val;
        dequeue(queueInput, &val);
        enqueue(queueOutput, val);
        enqueue(queueInput, val);
    }
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/