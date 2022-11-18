// Nama             : Wan Aufa Azis
// NIM              : 18221001
// Tanggal          : 03 Oktober 2022
// Topik Praktikum  : Mesin Karakter & Mesin Kata
// Deskripsi        : Menghitung jumlah kata yang anagram dengan "alstrukdat"

#include <stdio.h>
#include "anagramalstrukdat.h"


int hitung(char C, Word kata){
    int i = 0; 
    int nC = 0;
    while (i<kata.Length){
        if (kata.TabWord[i]==C){
            nC++;
        } i++;
    } return nC;
}

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string){
    int i = 0;
    while (string[i]!='\0'){
        i++;
    } return i;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
    Word kata;
    kata.Length = stringLength(command);
    for (int i = 0; i<kata.Length; i++){
        kata.TabWord[i]=command[i];
    }
    return kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
    if (string1.Length != string2.Length){
        return false;
    } else {
        int i = 0;
        boolean anagram = true;
        while ((i < string1.Length) && (anagram)){
            if (hitung(string1.TabWord[i],string1) == hitung(string1.TabWord[i],string2)){
                i++;
            } else {
                anagram = false;
            }
        } // i = string1.length or !anagram
        return anagram;
    }
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek){
    *frek = 0;

    STARTWORD();
    while (!isEndWord()){
        if (isAnagram(toKata("alstrukdat"),currentWord)){
            (*frek)++;
        } ADVWORD();
    }
}