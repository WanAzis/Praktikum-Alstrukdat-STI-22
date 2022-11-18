// Wan Aufa Azis - 18221001
// 18 September 2022

// IMPLEMENTASI ADT ARRAY DINAMIS

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    // KAMUS LOKAL
    ArrayDin arr;
    // ALGORITMA
    arr.A = (ElType *) malloc (InitialSize * sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    // KAMUS LOKAL

    // ALGORITMA
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    // KAMUS LOKAL

    // ALGORITMA
    return array.Neff==0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    // KAMUS LOKAL

    // ALGORITMA
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    // KAMUS LOKAL
    
    // ALGORITMA
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    // KAMUS LOKAL

    // ALGORITMA
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    // KAMUS LOKAL
    int j = array->Neff;
    // ALGORITMA
    if (array->Neff == array->Capacity){
        array->A = (ElType *) realloc (array->A, 2 * array->Capacity * sizeof(ElType));
        array->Capacity *= 2;
    }
    for (j;j>i;j--) {
        array->A[j] = array->A[j-1];
    } array->A[i] = el;
    array->Neff += 1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    // KAMUS LOKAL

    // ALGORITMA
    for (int j = i; j < array->Neff - 1; j++) {
        array->A[j] = array->A[j + 1];
    }
    array->Neff--;
}