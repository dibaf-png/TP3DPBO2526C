#include <iostream>  //library utama C++ untuk fungsi input-output standar (cout, cin, endl)
#include <vector>    //library untuk mengelola struktur data array dinamis (vector)
#include <string>    //library untuk tipe data teks (string)
#include <limits>    //library untuk mendapatkan nilai batas tipe data (digunakan pada cin.ignore)
#include <iomanip>   //library untuk memformat tampilan output teks

using namespace std; // Menghindari penulisan std:: secara berulang pada fungsi standar C++

// Mengimpor file-file definisi kelas pendukung yang terpisah
#include "MetodePemesanan.cpp"     
#include "ItemPesanan.cpp"           
#include "MetodePembayaran.cpp"      
#include "DriveThru.cpp"             
#include "SelfService.cpp"            
#include "TableService.cpp"           
#include "OnlineDelivery.cpp"         
#include "Pesanan.cpp"                

// Struct untuk menyimpan struktur data sederhana menu makanan
struct Menu {
    string nama; // Variabel untuk menyimpan nama menu makanan/minuman
    int harga;  // Variabel untuk menyimpan harga menu
};

// Vector global yang menyimpan daftar menu makanan dan harganya
vector<Menu> daftarMenu = {
    {"Burger Keju", 35000},
    {"Kentang Goreng", 18000},
    {"Ice Coffe", 18500},
};

// Fungsi untuk membersihkan buffer input (sisa enter '\n' atau karakter tersisa di cin)
void bersihkanInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus sisa input hingga menemukan newline
}

// Fungsi untuk menerima input berupa teks string dari pengguna dengan validasi non-kosong
string inputTeks(string pesan) {
    string hasil; // Variabel penampung hasil input teks

    while (true) { // Perulangan akan terus berjalan sampai input valid diberikan
        cout << pesan; // Menampilkan petunjuk input ke layar
        getline(cin, hasil); // Membaca seluruh baris teks yang diinput pengguna

        if (!hasil.empty()) { // Mengecek apakah string tidak kosong
            return hasil; // Mengembalikan nilai string jika valid
        }

        cout << "Input tidak boleh kosong!" << endl; // Pesan peringatan jika input kosong
    }
}

// Fungsi untuk menerima input angka dengan rentang nilai minimum dan maksimum
int inputAngka(string pesan, int minimum, int maksimum) {
    int angka; // Variabel penampung input angka

    while (true) { // Perulangan validasi input angka
        cout << pesan; // Menampilkan pesan petunjuk input

        if (cin >> angka) { // Mengecek apakah input yang dimasukkan adalah tipe data integer yang valid
            if (angka >= minimum && angka <= maksimum) { // Memastikan angka berada dalam batas rentang
                bersihkanInput(); // Membersihkan sisa karakter enter pada buffer
                return angka; // Mengembalikan nilai angka yang valid
            }
        }

        cin.clear(); // Mengembalikan status cin dari keadaan error/fail state
        bersihkanInput(); // Membersihkan sisa karakter salah dari buffer input
        cout << "Input tidak valid!" << endl; // Pesan peringatan jika input di luar rentang atau bukan angka
    }
}

// Fungsi untuk menerima input angka dengan batas nilai minimal tanpa batas maksimum
int inputAngkaMinimal(string pesan, int minimum) {
    int angka; // Variabel penampung input angka

    while (true) {
        cout << pesan; // Menampilkan pesan petunjuk input

        if (cin >> angka) { // Mengecek apakah input bernilai integer valid
            if (angka >= minimum) { // Memastikan angka lebih besar atau sama dengan batas minimal
                bersihkanInput();   // Membersihkan sisa enter pada buffer
                return angka; // Mengembalikan angka yang valid
            }
        }

        cin.clear(); // Reset status error pada cin
        bersihkanInput();  // Membersihkan buffer dari karakter yang salah
        cout << "Input tidak valid!" << endl; // Menampilkan pesan kesalahan
    }
}

// Fungsi untuk menerima input persetujuan berbentuk karakter 'y' atau 'n'
char inputYaTidak() {
    char pilihan; // Variabel penampung karakter pilihan

    while (true) {
        cin >> pilihan; // Menerima input karakter dari layar
        bersihkanInput();  // Membersihkan sisa enter pada buffer

        if (pilihan == 'y' || pilihan == 'Y') { // Mengecek opsi 'y' atau 'Y'
            return 'y'; // Mengembalikan karakter 'y' konsisten
        }

        if (pilihan == 'n' || pilihan == 'N') { // Mengecek opsi 'n' atau 'N'
            return 'n'; // Mengembalikan karakter 'n' konsisten
        }

        cout << "Masukkan hanya y atau n: "; // Peringatan jika pengguna memasukkan karakter selain y/n
    }
}

// Prosedur untuk mencetak daftar menu makanan yang tersedia ke layar
void tampilMenu() {
    cout << endl;
    cout << "     <<<<<<<<<< DAFTAR MENU >>>>>>>>>>    " << endl;

    // Perulangan untuk mencetak seluruh elemen dari vector daftarMenu
    for (size_t i = 0; i < daftarMenu.size(); i++) {
        cout << i + 1 << ". "; // Menampilkan nomor urut menu
        cout << daftarMenu[i].nama; // Menampilkan nama menu makanan
        cout << " - Rp." << daftarMenu[i].harga << endl; // Menampilkan harga menu makanan
    }
}

// Prosedur untuk mencetak seluruh data pesanan yang telah tersimpan dalam daftarPesanan
void tampilkanSemuaPesanan(vector<Pesanan>& daftarPesanan) {
    if (daftarPesanan.empty()) { // Mengecek apakah vector daftarPesanan masih kosong
        cout << endl;
        cout << "Belum ada data pesanan." << endl; // Menampilkan pesan jika tidak ada transaksi
        return; // Menghentikan eksekusi prosedur
    }

    // Perulangan untuk memanggil method tampilPesanan() dari setiap objek Pesanan
    for (size_t i = 0; i < daftarPesanan.size(); i++) {
        daftarPesanan[i].tampilPesanan(); // Memanggil method cetak rincian pesanan
        cout << endl; // Jarak antar daftar pesanan
    }
}

// Fungsi utama tempat program mengeksekusi alur pemesanan makanan
int main() {
    // Vector tempat menyimpan kumpulan objek transaksi Pesanan
    vector<Pesanan> daftarPesanan;

    // Vector penampung objek spesifik dari masing-masing jenis metode pemesanan
    vector<DriveThru> daftarDriveThru;
    vector<SelfService> daftarSelfService;
    vector<TableService> daftarTableService;
    vector<OnlineDelivery> daftarOnlineDelivery;

    // Menyiapkan alokasi memori awal agar alamat pointer objek di dalamnya tidak berubah saat push_back
    daftarDriveThru.reserve(100);
    daftarSelfService.reserve(100);
    daftarTableService.reserve(100);
    daftarOnlineDelivery.reserve(100);

    int pilihanMenu; // Variabel untuk menyimpan pilihan menu utama aplikasi

    do { // Perulangan menu utama berjalan minimal satu kali
        cout << endl;
        cout << "     <<<<<<<<<< SISTEM PEMESANAN MAKANAN >>>>>>>>>>  " << endl;
        cout << "1. Tambah Data Pesanan" << endl;
        cout << "2. Tampilkan Data Pesanan" << endl;
        cout << "3. Keluar" << endl;

        pilihanMenu = inputAngka("Pilih menu : ", 1, 3); // Menerima pilihan angka menu utama dari user

        switch (pilihanMenu) { // Percabangan eksekusi berdasarkan pilihan menu
        case 1: {
            Pesanan pesananBaru; // Membuat objek transaksi Pesanan baru

            cout << endl;
            cout << "========== DATA PELANGGAN ==========" << endl;
            string namaPelanggan = inputTeks("Nama Pelanggan : ");   // Meminta nama pelanggan
            string waktuPemesanan = inputTeks("Waktu Pemesanan : "); // Meminta waktu/jam pemesanan

            cout << endl;
            cout << "========== METODE PEMESANAN ==========" << endl;
            cout << "1. Drive Thru" << endl;
            cout << "2. Self Service" << endl;
            cout << "3. Table Service" << endl;
            cout << "4. Online Delivery" << endl;

            int pilihanMetode = inputAngka("Pilih metode pemesanan : ", 1, 4); // Meminta pilihan opsi pemesanan

            MetodePemesanan* metodeTerpilih = nullptr; // Pointer kelas induk untuk menunjuk ke objek metode spesifik

            if (pilihanMetode == 1) { // Opsi Drive Thru
                cout << endl;
                cout << "========== DRIVE THRU ==========" << endl;
                string nomorKendaraan = inputTeks("Nomor Kendaraan : "); // Input plat nomor
                string jenisKendaraan = inputTeks("Jenis Kendaraan : "); // Input jenis kendaraan (misal: Mobil)

                // Menambahkan objek DriveThru baru ke dalam vector penampung DriveThru
                daftarDriveThru.push_back(DriveThru(namaPelanggan, waktuPemesanan, nomorKendaraan, jenisKendaraan));
                metodeTerpilih = &daftarDriveThru.back(); // Mengambil alamat memori dari objek DriveThru yang baru dimasukkan
            }
            else if (pilihanMetode == 2) { // Opsi Self Service
                // Menambahkan objek SelfService baru ke dalam vector
                daftarSelfService.push_back(SelfService(namaPelanggan, waktuPemesanan));
                metodeTerpilih = &daftarSelfService.back(); // Mengambil alamat memori objek SelfService terbaru
            }
            else if (pilihanMetode == 3) { // Opsi Table Service
                cout << endl;
                cout << "========== TABLE SERVICE ==========" << endl;
                int jumlahPelanggan = inputAngkaMinimal("Jumlah Pelanggan : ", 1); // Input jumlah pelanggan di meja

                // Menambahkan objek TableService baru ke dalam vector
                daftarTableService.push_back(TableService(namaPelanggan, waktuPemesanan, jumlahPelanggan));
                metodeTerpilih = &daftarTableService.back(); // Mengambil alamat memori objek TableService terbaru
            }
            else if (pilihanMetode == 4) { // Opsi Online Delivery
                cout << endl;
                cout << "========== ONLINE DELIVERY ==========" << endl;
                cout << "1. GoFood" << endl;
                cout << "2. ShopeeFood" << endl;
                cout << "3. GrabFood" << endl;

                int pilihanPlatform = inputAngka("Pilih platform : ", 1, 3); // Input opsi aplikasi pengantar
                string platform;

                if (pilihanPlatform == 1) {
                    platform = "GoFood";
                }
                else if (pilihanPlatform == 2) {
                    platform = "ShopeeFood";
                }
                else {
                    platform = "GrabFood";
                }

                string alamat = inputTeks("Alamat Pengantaran : "); // Input alamat tujuan
                int jarak = inputAngkaMinimal("Jarak Pengantaran (km) : ", 1); // Input jarak dalam kilometer

                // Menambahkan objek OnlineDelivery baru (diperbaiki penggunaan nama variabel 'platform')
                daftarOnlineDelivery.push_back(OnlineDelivery(namaPelanggan, waktuPemesanan, platform, alamat, jarak));
                metodeTerpilih = &daftarOnlineDelivery.back(); // Mengambil alamat memori objek OnlineDelivery terbaru
            }

            // Menyimpan alamat pointer metode pemesanan dan tipe jenis metodenya ke objek pesananBaru
            pesananBaru.setCaraPemesanan(metodeTerpilih, pilihanMetode);

            tampilMenu(); // Menampilkan daftar seluruh makanan dan minuman ke layar

            char tambahLagi = 'y'; // Variabel kontrol perulangan penambahan makanan

            while (tambahLagi == 'y') {
                int pilihanMakanan = inputAngka("Pilih menu : ", 1, daftarMenu.size()); // Memilih nomor menu
                int jumlah = inputAngkaMinimal("Masukkan jumlah : ", 1);                 // Meminta kuantitas pesanan

                string namaMakanan = daftarMenu[pilihanMakanan - 1].nama; // Mengambil nama makanan sesuai indeks (1-based index)
                int hargaMakanan = daftarMenu[pilihanMakanan - 1].harga; // Mengambil harga makanan sesuai indeks

                ItemPesanan itemBaru(namaMakanan, hargaMakanan, jumlah); // Instansiasi objek ItemPesanan
                pesananBaru.tambahPesanan(itemBaru); // Memasukkan item ke dalam objek pesananBaru

                cout << "Tambah menu lagi? [y/n]: ";
                tambahLagi = inputYaTidak(); // Konfirmasi penambahan item makanan berikutnya
            }

            int biayaKirim = 0; // Menginisialisasi biaya kirim default 0

            if (pilihanMetode == 4) { // Pengecekan jika metode yang dipilih adalah Online Delivery
                OnlineDelivery* dataOnlineDelivery = static_cast<OnlineDelivery*>(metodeTerpilih); // Konversi pointer
                biayaKirim = dataOnlineDelivery->getBiayaKirim(); // Mengambil kalkulasi biaya kirim dari objek OnlineDelivery
            }

            pesananBaru.hitungTotal(biayaKirim); // Mengalkulasi total biaya keseluruhan pesanan

            cout << endl;
            cout << "========== RINCIAN PEMBAYARAN ==========" << endl;
            int subtotal = pesananBaru.getTotalBayar() - biayaKirim; // Kalkulasi murni harga makanan/minuman saja

            cout << "Subtotal Pesanan : Rp." << subtotal << endl;
            cout << "Biaya Kirim      : Rp." << biayaKirim << endl;
            cout << "Total Bayar      : Rp." << pesananBaru.getTotalBayar() << endl;

            cout << endl;
            cout << "========== METODE PEMBAYARAN ==========" << endl;
            cout << "1. Cash" << endl;
            cout << "2. Debit" << endl;
            cout << "3. QRIS" << endl;
            cout << "4. E-Wallet" << endl;

            int pilihanPembayaran = inputAngka("Pilih metode pembayaran : ", 1, 4); // Input opsi pembayaran
            string jenisPembayaran;

            if (pilihanPembayaran == 1) {
                jenisPembayaran = "Cash";
            }
            else if (pilihanPembayaran == 2) {
                jenisPembayaran = "Debit";
            }
            else if (pilihanPembayaran == 3) {
                jenisPembayaran = "QRIS";
            }
            else {
                jenisPembayaran = "E-Wallet";
            }

            pesananBaru.setJenisPembayaran(jenisPembayaran); // Menandai tipe metode pembayaran pada transaksi
            pesananBaru.bayarPesanan(); // Memproses nomor transaksi dan status pembayaran

            cout << endl;
            cout << "Data berhasil ditambahkan!" << endl;

            daftarPesanan.push_back(pesananBaru); // Memasukkan objek transaksi yang selesai ke dalam vector daftarPesanan
            break;
        }
        case 2: {
            tampilkanSemuaPesanan(daftarPesanan); // Menampilkan daftar riwayat transaksi yang tersimpan
            break;
        }
        case 3: {
            cout << endl;
            cout << "Program selesai. Terima kasih!" << endl; // Pesan penutup sebelum keluar dari aplikasi
            break;
        }
        }

    } while (pilihanMenu != 3); // Perulangan akan berhenti saat pilihanMenu sama dengan 3

    return 0; // Mengembalikan nilai 0 penanda program selesai dieksekusi dengan sukses
}