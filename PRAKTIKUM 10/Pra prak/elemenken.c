// Wan Aufa Azis - 18221001
// 12 November 2022

// Implementasi ADT List Berkait dengan representasi sirkuler

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P = First(L);
    for (int i = 0; i<r; i++){
        P = Next(P);
    }
    return Info(P);
}

int main () {
  List L; CreateEmpty(&L);
  int r, input;
  scanf("%i", &input);
  while (input != 0){
    InsVLast(&L, input);
    scanf("%i", &input);
  } // input = 0
  scanf("%i", &r);

  if (IsEmpty(L)){
    printf("List Kosong\n");
  } else {
    printf("%d\n", ElemenKeN(L, r));
  }
  return 0;
}