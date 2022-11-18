/* Nama    : Wan Aufa Azis */
/* NIM     : 18221001 */
/* Tanggal : 05 September 2022 */

/* PROGRAM WUJUD AIR */
/* Menerima inputan suhu air, kemudian mencetak wujudnya ke layar */

#include <stdio.h>
int main()
{
    /* KAMUS */
    float SUHU;

    /* ALGORITMA */
    scanf("%f", &SUHU);

    if (SUHU < 0) {
        printf("Suhu air padat");
    } else if (SUHU >= 0 && SUHU <= 100) {
        printf("Suhu air cair");
    } else { printf("Suhu air gas"); }
    
    return 0;
}
