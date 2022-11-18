// Wan Aufa Azis - 18221001
// 07 November 2022
// ADT List Linier

#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el, val;
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        scanf("%i", &val);
        InsVLast(&fibonacci,val);

        PrintInfo(fibonacci);
        return 0;
    } else {
        scanf("%i", &val);
        InsVLast(&fibonacci,val);
        scanf("%i", &val);
        InsVLast(&fibonacci,val);
        address P = First(fibonacci);
        address NextP = Next(First(fibonacci));
        for(int i = 2; i<el; i++){
            int sum = Info(P)+Info(NextP);
            InsVLast(&fibonacci,sum);
            P = NextP;
            NextP=Next(NextP);
        }
        PrintInfo(fibonacci);
    }

    return 0;
}