/*Wan Aufa Azis - 18221001*/
/*11 September 2022*/

/*PROGRAM BANDING STRING*/
/*Membandingkan dua buah string apakah mengadung kalimat yang sama
  lalu mencetak ke layar Ya/Tidak*/

#include <stdio.h>
#include <string.h>

int main(){
    int i;
    char kalimat1[100], kalimat2[100];

    scanf("%s",kalimat1);
    scanf("%s",kalimat2);

    if (strcmp(kalimat1, kalimat2)==0) {
        printf("Ya\n");
        return 0;
    }
    if (strlen(kalimat1) != strlen(kalimat2)) {
        printf("Tidak\n");
        return 0;
    }
    for (i=0;i<=strlen(kalimat1);i++) {
        if (kalimat1[i] >= 65 && kalimat1[i] <= 90) {
            if ((kalimat1[i] != kalimat2[i]) && (kalimat2[i] != kalimat1[i]+32)) {
                printf("Tidak\n");
                return 0;
            }
        } else if (kalimat1[i] >= 97 && kalimat1[i] <= 122) {
            if ((kalimat1[i] != kalimat2[i]) && (kalimat2[i] != kalimat1[i]-32)) {
                printf("Tidak\n");
                return 0;
        }
    }
    } printf("Ya\n");
    return 0;
}