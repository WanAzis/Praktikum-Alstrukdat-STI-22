// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 17 Oktober 2022
// Topik        : ADT Queue
// Deskripsi    : Program Queue Restoran


/* Ibu Gra adalah pemilik dari restoran bintag 5, Aldat, dan terkadang 
datang ke restoran tersebut untuk melihat kondisi di lapangan dan 
membantu memasak. Tidak seperti para koki yang lainnya, Ibu Gra 
hanya dapat memasak 1 masakan untuk 1 waktunya, dengan setiap 
masakannya membutuhkan waktu yang berbeda-beda, dan tamu-tamu lainnya 
dapat melakukan permintaan untuk mendapat masakan dari Ibu Gra, 
karena masakannya yang sangat populer dan juga viral di social media. 
Suatu hari, Ibu Gra ingin mengetahui berapa jumlah masakan yang telah disajikan, 
waktu minimal yang dibutuhkan, dan waktu maksimal yang dibutuhkan 
pada 1 hari tertentu. Menurut Ibu Gra, masalah ini dapat diselesaikan 
dengan membuat kode dalam bahasa C.

Spesifikasi program:

    Input berupa angka, yaitu 0, 1, dan 2. 0 berarti program berhenti menerima masukan. 
    1 berarti menerima permintaan (dengan tambahan parameter adalah waktu yang dibutuhkan dan waktu yang tidak valid akan diabaikan). 
    2 berarti menyajikan masakan.\
    Output berupa jumlah masakan yang disaji, waktu minimal yang dibutuhkan, dan waktu maksimal yang dibutuhkan (diikuti dengan newline). Default value adalah 0.
    Nama file adalah restoran.c, dengan menggunakan header dari queue.h. */

#include <stdio.h>
#include "queue.h"

int main(){
    Queue antrian;
    CreateQueue(&antrian);
    int  perintah, waktu;
    int count_masak=0, waktu_min, waktu_maks;

    scanf("%i", &perintah);
    while (perintah!=0){
        if (perintah==1){
            scanf("%i", &waktu);
            if (waktu > 0 && !isFull(antrian)){ //cek waktu valid
                enqueue(&antrian, waktu);
            }
        } else if (perintah==2){
            if (count_masak<length(antrian)){
                count_masak++;
            } // Asumsi makanan tidak bisa disajikan jika belum ada pesanan
        }
        scanf("%i", &perintah);
    }
    // Pengecekan waktu minimum dan waktu maksimum
    if (count_masak==0){
        waktu_maks=0;
        waktu_min=0;
    } else {
    int Loop=count_masak;
    ElType val = HEAD(antrian);
    waktu_maks=val;
    waktu_min=val;
    for (int i = 0; i<Loop; i++){
        dequeue(&antrian,&val);
        if (val>waktu_maks){
            waktu_maks=val;
        }
        if (val<waktu_min){
            waktu_min=val;
        }
    }
    }
    printf("%i\n", count_masak);
    printf("%i\n", waktu_min);
    printf("%i\n", waktu_maks);
}