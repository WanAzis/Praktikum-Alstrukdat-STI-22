// Wan Aufa Azis - 18221001
// 19 September 2022

// PROGRAM ARRAY DINAMIS
// IMPLEMENTASI ADT ARRAY

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
    ArrayDin arr;
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
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    return array.Neff==0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    if (array->Neff == array->Capacity) {
        array->Capacity *= 2;
        array->A = (ElType *) realloc (array->A, array->Capacity * sizeof(ElType));
    }
    int j;    
    for (j = Length(*array); j>i; j--) {
        array->A[j] = array->A[j-1];
    } array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array,el,Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array,el,0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    for (int j=i;j<array->Neff-1;j++) {
        array->A[j] = array->A[j+1];
    } array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
    DeleteAt(array,Length(*array)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array,0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array)
{
    if (IsEmpty(array)){
        printf("[]\n");
    } else {
    printf("[");
    for (int i = 0;i<array.Neff-1;i++) {
        printf("%d, ", array.A[i]);
    } printf("%d",array.A[array.Neff-1]);
    printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array)
{
    int i = 0, j = Length(*array)-1;
    int temp;
    while (i<j){
        temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
        i++; j--;
    }
    /*ArrayDin temp;
    // ArrayDin *array;
    temp = CopyArrayDin(*array);
    DeallocateArrayDin(array);
    *array = MakeArrayDin();
    for (int i = 0; i<temp.Neff; i++) {
        array->A[i] = temp.A[temp.Neff-i-1];
    } array->Neff = temp.Neff;
    DeallocateArrayDin(&temp);*/
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array)
{
    ArrayDin arr;
    arr = MakeArrayDin();
    for (int i = 0; i<array.Neff;i++) {
        arr.A[i] = array.A[i];
    } arr.Neff = array.Neff;
    return arr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    int i = 0;
    while (array.A[i] != el && i<Length(array)) {
        i++;
    } 
    if (i==Length(array)){
        return -1;
    } else {return i;}
}