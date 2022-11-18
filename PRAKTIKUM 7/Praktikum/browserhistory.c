// Wan Aufa Azis - 18221001
// 24 Oktober 2022

// Implementasi ADT Stack

#include <stdio.h>
#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url){
    Push(openedTab, url);
    browserHistoryFree(history);
}
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */


char *currentUrl(Stack *openedTab){
    return InfoTop(*openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps){
    for (int i = 1; i<=steps; i++){
        infotype temp;
        Pop(openedTab, &temp);
        Push(history, temp);
    }
    // return InfoTop(*openedTab);
    return currentUrl(openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps){
    for (int i = 1; i<=steps; i++){
        infotype temp;
        Pop(history, &temp);
        Push(openedTab, temp);
    }
    // return InfoTop(*openedTab);
    return currentUrl(openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */

void browserHistoryFree(Stack *history){
    Top(*history)=Nil;
}
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */