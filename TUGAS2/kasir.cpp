#include <stdio.h>
#include <time.h>

// Prosedur tanpa parameter
void tampilkanDaftarBarang() {
    printf("\n===== DAFTAR BARANG =====\n");
    printf("1. Sarden  : Rp15000\n");
    printf("2. Sabun   : Rp5000\n");
    printf("3. Minyak  : Rp25000\n");
    printf("4. Gula    : Rp18000\n");
}

// Fungsi dengan parameter dan nilai balik
int hitungSubtotal(int harga, int jumlah) {
    return harga * jumlah;
}

// Fungsi dengan nilai balik
float hitungPajak(float total) {
    return total * 0.11; // PPN 11%
}

// Prosedur dengan parameter
void cetakStruk(float total, float diskon, float pajak, float bayar) {
    printf("\n===== STRUK PEMBELIAN =====\n");
    printf("Total Belanja : Rp%.2f\n", total);
    printf("Diskon        : Rp%.2f\n", diskon);
    printf("Pajak (11%%)   : Rp%.2f\n", pajak);
    printf("Total Bayar   : Rp%.2f\n", bayar);

    time_t t;
    time(&t);
    printf("Tanggal       : %s", ctime(&t));
}

int main() {
    char ulang;

    do {
        int pilihan, jumlah;
        int harga = 0;
        float total, diskon = 0, pajak, bayar;

        tampilkanDaftarBarang();

        printf("\nPilih Barang (1-4): ");
        scanf("%d", &pilihan);

        printf("Jumlah Beli: ");
        scanf("%d", &jumlah);

        // Percabangan
        switch (pilihan) {
            case 1:
                harga = 15000;
                break;
            case 2:
                harga = 5000;
                break;
            case 3:
                harga = 25000;
                break;
            case 4:
                harga = 18000;
                break;
            default:
                printf("Pilihan tidak tersedia!\n");
                continue;
        }

        total = hitungSubtotal(harga, jumlah);

        // Percabangan diskon
        if (total >= 100000) {
            diskon = total * 0.10; // 10%
        }

        total -= diskon;

        pajak = hitungPajak(total);

        bayar = total + pajak;

        cetakStruk(total, diskon, pajak, bayar);

        printf("\nIngin transaksi lagi? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    printf("\nTerima kasih telah berbelanja.\n");

    return 0;
}