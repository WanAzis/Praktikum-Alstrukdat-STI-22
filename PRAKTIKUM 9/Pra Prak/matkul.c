/* Dengan menggunakan ADT List Linier dengan representasi fisik pointer yang Anda buat
pada soal 1, buatlah program yang mengelola statistik daftar nilai sebuah mata kuliah
(asumsikan nilai selalu 0..100) sebagai berikut:

1. Membuat sebuah list kosong untuk menyimpan daftar nilai mata kuliah.
2. Untuk setiap list: Membaca sekumpulan nilai integer dari keyboard sampai
pengguna memasukkan angka di luar range nilai (di luar 0..100). Setiap elemen
ditambahkan sebagai elemen pertama.
3. Jika list tidak kosong, menuliskan:
    ○ Ada berapa banyak nilai yang ada di daftar
    ○ Nilai tertinggi yang ada di daftar.
    ○ Nilai terendah yang ada di daftar.
    ○ Nilai rata-rata (presisi: 2 digit di belakang koma).
    ○ Mengkopi isi daftar ke sebuah list yang lain dan membalik isinya dan
       menuliskan isinya.
    ○ Menuliskan isi daftar yang asli (sebelum dibalik).
4. Jika list kosong, menuliskan “Daftar nilai kosong“. */

// Wan Aufa Azis - 18221001
// 06 November 2022
// Implementasi ADT List Linier

#include <stdio.h>
#include "listlinier.h"

void CopyList (List L1, List* L2){
    CreateEmpty(L2);
    address P = First(L1);
    while(P!=Nil){
        InsVLast(L2, Info(P));
        P = Next(P);
    }
}
int main(){
    List L; CreateEmpty(&L);
    int X;
    scanf("%i", &X);
    while(X>=0 && X<=100){
        InsVFirst(&L,X);
        scanf("%i", &X);
    }
    if (!IsEmpty(L)){
        int count = NbElmt(L), maks = Max(L), mins = Min(L);
        float avg = Average(L);
        List copy; CreateEmpty(&copy);
        CopyList(L, &copy);
        printf("%i\n", count);
        printf("%i\n", maks);
        printf("%i\n", mins);
        printf("%.2f\n", avg);
        InversList(&copy);
        PrintInfo(copy); printf("\n");
        PrintInfo(L); printf("\n");
    }
    else {
        printf("Daftar nilai kosong\n");
    }
}