#include <stdio.h>

// Definisikan fungsi untuk mencari jumlah maksimum elemen yang dapat diambil dari dua tumpukan tanpa melebihi jumlah maksimum yang ditentukan
int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0, count = 0, temp = 0, i = 0, j = 0;

    // Hitung jumlah maksimum elemen yang dapat diambil dari tumpukan pertama (a) tanpa melebihi jumlah maksimum
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i++];
    }
    count = i; // Perbarui jumlah dengan jumlah elemen dari tumpukan pertama

    // Iterasi melalui tumpukan kedua (b) untuk mencari jumlah maksimum elemen yang dapat ditambahkan tanpa melebihi jumlah maksimum
    while (j < m && i >= 0) {
        sum += b[j++];
        // Hapus elemen dari tumpukan pertama sampai jumlahnya dalam batas maksimum
        while (sum > maxSum && i > 0) {
            sum -= a[--i];
        }
        // Perbarui jumlah jika jumlah saat ini dalam batas dan jumlah total elemen lebih besar
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    return count; // Kembalikan jumlah maksimum elemen yang dapat diambil dari kedua tumpukan
}

int main() {
    int g;
    scanf("%d", &g); // Input jumlah kasus uji
    while (g--) {
        int n, m, maxSum;
        scanf("%d%d%d", &n, &m, &maxSum); // Input jumlah elemen dan jumlah maksimum untuk setiap kasus uji
        int a[n], b[m];
        // Input elemen-elemen dari tumpukan pertama (a)
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        // Input elemen-elemen dari tumpukan kedua (b)
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        printf("%d\n", twoStacks(maxSum, a, n, b, m)); // Cetak jumlah maksimum elemen yang dapat diambil
    }
    return 0;
}
