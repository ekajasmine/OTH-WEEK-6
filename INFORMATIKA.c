#include <stdio.h>

// Mendefinisikan struct Batu untuk menyimpan HURUF
struct Batu {
    char HURUF;  // Menyimpan huruf pada batu
    struct Batu *link;  // Pointer ke Batu berikutnya dalam urutan
};

int main() {
    // Inisialisasi batu-batu
    struct Batu l1, l2, l3, l4, l5, l6, l7, l8, l9;

    // Mengatur link dan huruf untuk setiap batu
    l1.link = NULL; l1.HURUF = 'F';
    l2.link = NULL; l2.HURUF = 'M';
    l3.link = NULL; l3.HURUF = 'A';
    l4.link = NULL; l4.HURUF = 'I';
    l5.link = NULL; l5.HURUF = 'K';
    l6.link = NULL; l6.HURUF = 'T';
    l7.link = NULL; l7.HURUF = 'N';
    l8.link = NULL; l8.HURUF = 'O';
    l9.link = NULL; l9.HURUF = 'R';

    // Mengatur koneksi antara batu-batu
    l7.link = &l1; l1.link = &l8; l8.link = &l2; l2.link = &l5;
    l5.link = &l3; l3.link = &l6; l6.link = &l9; l9.link = &l4;
    l4.link = &l7;

    // Mengakses dan mencetak huruf pada batu menggunakan l3 sebagai titik awal
    printf("%c", l3.link->link->link->HURUF); // Cetak huruf ke-3
    printf("%c", l3.link->link->link->link->HURUF); // Cetak huruf ke-4
    printf("%c", l3.link->link->link->link->link->HURUF); // Cetak huruf ke-5
    printf("%c", l3.link->link->link->link->link->link->HURUF); // Cetak huruf ke-6
    printf("%c", l3.link->link->HURUF); // Cetak huruf ke-2
    printf("%c", l3.link->link->link->link->link->link->link->HURUF); // Cetak huruf ke-7
    printf("%c", l3.HURUF); // Cetak huruf ke-1
    printf("%c", l3.link->HURUF); // Cetak huruf ke-2
    printf("%c", l3.link->link->link->HURUF); // Cetak huruf ke-4
    printf("%c", l3.link->link->link->link->link->link->link->link->HURUF); // Cetak huruf ke-9
    printf("%c", l3.HURUF); // Cetak huruf ke-1

    return 0;
}
