// Nama         : Wan Aufa Azis
// NIM          : 18221001
// Tanggal      : 31 Oktober 2022
// Topik        : ADT Set
// Deskripsi    :

#include <stdio.h>
#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
    Set s;
    CreateEmpty(&s);
    for (int i = 0; i<arrSize; i++){
        Insert(&s, arr[i]);
    }
    return s;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
    Set s = arrToSet(arr, arrSize);
    (*arrResSize)=0;
    for (int i = 0; i<s.Count; i++){
        int j = *arrResSize;
        arrRes[j]=s.Elements[i];
        while(j>0 && arrRes[j]>arrRes[j-1]){
            int temp = arrRes[j];
            arrRes[j] = arrRes[j-1];
            arrRes[j-1] = temp;
            j--;
        } // j<0 or nemu tempat yg tepat
        (*arrResSize)++;
    }
}