// Nama             : Wan Aufa Azis
// NIM              : 18221001
// Tanggal          : 03 Oktober 2022
// Topik Praktikum  : Mesin Karakter & Mesin Kata
// Deskripsi        : Menghitung frekuensi kemunculan kata 'tiga'

#include "hitungfrekuensi.h"

int hitungfrekuensi(){
    //membuat boolean untuk mengecek penemuan huruf t,i,g secara berurutan
    boolean t_found=false;
    boolean i_found=false;
    boolean g_found=false;
    
    int count=0;//inisiasi jumlah huruf t,i,g dan a berurutan
    
    START();//memulai mesin kata
    
    while(!IsEOP()){//melakukan looping hingga EOP
        if(GetCC()=='t'||GetCC()=='T'){//melakukan pengecekan apakah karakter yang dibaca t/T
            t_found=true;
        }
        else if (t_found==true&&(GetCC()=='i'||GetCC()=='I')){//melakukan pengecekan apakah karakter yang dibaca i/I dan karakter sebelumnya adalah t/T
            i_found=true;
            t_found=false;
        }
        else if (i_found==true&&(GetCC()=='g'||GetCC()=='G')){//melakukan pengecekan apakah karakter yang dibaca g/G dan karakter sebelumnya adalah i/I yang diawali dengan t/T
            g_found=true;
            i_found=false;
        }
        else if (g_found==true&&(GetCC()=='a'||GetCC()=='A')){//melakukan pengecekan apakah karakter yang dibaca a/A dan karakter sebelumnya adalah g/G yang diawali dengan t/T dan i/I
            count++;//menambah jumlah counter, karena pada titik ini huruf a sudah pasti muncul setelah t,i,g secara berurutan
           
            //mengembalikan status boolean ke awal(agar tidak terjadi salah perhitungan apabila muncul lebih dari 1 huruf a dibelakang. Contoh: tigaaaaa.)
            g_found=false;
        }
        else{//membuat semua boolean salah apabila huruf yang dibaca bukan t,i,g,a dan apabila huruf t,i,g,a tidak muncul secara berurutan
            t_found=false;
            i_found=false;
            g_found=false;
        }
        ADV();//memajukan mesin kata sebanyak 1 karakter
    }
    return count;
}