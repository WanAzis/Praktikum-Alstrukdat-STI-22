/*Wan Aufa Azis - 18221001*/
/*12 September 2022*/

/*PROGRAM INDEKS PRAKTIKUM*/
/*Menerima sebuah integer secara berulang hingga menerima input
  berupa -999. Lalu program akan menampilkan jumlah mahasiswa yang lulus,
  nilai rata-rata, dan indeks akhir kelas*/

#include <stdio.h>

int main()
{
    /*KAMUS*/
    int n,MLulus=0,count=0;
    float sum=0,rata;
    /*ALGORITMA*/
    scanf("%d",&n);
    while (n!=-999) 
    {
        if (n>=3 && n<=4) {
            MLulus += 1;
        }
        if (n>=0 && n<=4) {
            count += 1;
            sum += n;
        } scanf("%d",&n);
    } if (count == 0) {
        printf("Tidak ada data\n");
        return 0;
    } 
    rata = sum/count;
    printf("Jumlah mahasiswa yang lulus = %d\n",MLulus);
    printf("Nilai rata-rata = %.2f\n",rata);

    if (rata>=0 && rata<1) {
        printf("Indeks akhir kelas = E\n");
    } 
    else if (rata>=1 && rata<2) {
        printf("Indeks akhir kelas = D\n");
    }
    else if (rata>=2 && rata<3) {
        printf("Indeks akhir kelas = C\n");
    }
    else if (rata>=3 && rata<4) {
        printf("Indeks akhir kelas = B\n");
    }
    else if (rata==4) {
        printf("Indeks akhir kelas = A\n");
    }
    return 0;
}