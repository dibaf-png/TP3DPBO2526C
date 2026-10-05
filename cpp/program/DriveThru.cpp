#include <iostream> //mengimpor pustaka iostream untuk mendukung operasi input dan output seperti cout dan cin
#include <string>   //mengimpor pustaka string untuk menggunakan tipe data string

using namespace std; //menggunakan namespace standar agar tidak perlu menulis std:: sebelum string, cout, dan endl

//class DriveThru merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class DriveThru : public MetodePemesanan {
private: // Hak akses private agar atribut hanya bisa diakses langsung dari dalam class DriveThru ini sendiri
    string nomorKendaraan; //variabel nomorKendaraan bertipe string untuk menyimpan plat nomor kendaraan
    string jenisKendaraan; //variabel jenisKendaraan bertipe string untuk menyimpan jenis kendaraan (Mobil/Motor)
    int nomorLoket; //variabel nomorLoket bertipe int untuk menyimpan nomor loket pelayanan

public: // Hak akses public agar method dan konstruktor dapat dipanggil dari luar class
    //constructor untuk membuat object DriveThru dan memanggil constructor dari superclass MetodePemesanan
    DriveThru(string namaPelanggan, string waktuPemesanan, string nomorKendaraan, string jenisKendaraan) : MetodePemesanan(namaPelanggan, waktuPemesanan) { // Memanggil konstruktor induk dengan parameter namaPelanggan dan waktu
        this->nomorKendaraan = nomorKendaraan; //mengisi atribut nomorKendaraan dengan data dari parameter nomorKendaraan
        this->jenisKendaraan = jenisKendaraan; //mengisi atribut jenisKendaraan dengan data dari parameter jenisKendaraan
        this->cekLoket(); //memanggil method cekLoket() untuk menentukan nomor loket secara otomatis saat objek dibuat
    }

    //getter untuk mengambil dan mengembalikan nilai dari atribut nomorKendaraan
    string getNomorKendaraan() {
        return nomorKendaraan; //mengembalikan string nomorKendaraan
    }

    //getter untuk mengambil dan mengembalikan nilai dari atribut jenisKendaraan
    string getJenisKendaraan() {
        return jenisKendaraan; //mengembalikan string jenisKendaraan
    }

    //getter untuk mengambil danmengembalikan nilai dari atribut nomorLoket
    int getNomorLoket() {
        return nomorLoket; //mengembalikan nilai integer nomorLoket
    }

    //setter untuk memperbarui atau mengubah data nomorKendaraan
    void setNomorKendaraan(string nomorKendaraan) {
        this->nomorKendaraan = nomorKendaraan; //memperbarui nilai atribut nomorKendaraan
    }

    //setter untuk memperbarui atau mengubah data jenisKendaraan
    void setJenisKendaraan(string jenisKendaraan) {
        this->jenisKendaraan = jenisKendaraan; //memperbarui nilai atribut jenisKendaraan
    }

    //untuk menentukan dan mengalokasikan nomor loket secara bergantian
    void cekLoket() {
        static int loket = 1; //variabel static untuk menyimpan nomor loket aktif 
        this->nomorLoket = loket;  //mengisi atribut nomorLoket dengan nilai loket saat ini
        loket++; //menambahkan nilai loket sebanyak 1 untuk pengalokasian berikutnya

        if (loket > 3) { //jika nilai loket melampaui 3
            loket = 1; //mengembalikan nomor loket ke angka 1
        }
    }

    //untuk menampilkan seluruh informasi detail pemesanan layanan Drive Thru
    void tampilDriveThru() {
        cout << "Metode Pemesanan  : Drive Thru" << endl; //mencetak jenis metode pemesanan
        this->tampilMetode(); //memanggil method tampilMetode() milik superclass untuk mencetak ID, Nama, dan Waktu
        cout << "Nomor Kendaraan   : " << nomorKendaraan << endl; //mencetak plat nomor kendaraan
        cout << "Jenis Kendaraan   : " << jenisKendaraan << endl; //mencetak jenis kendaraan
        cout << "Nomor Loket       : " << nomorLoket << endl; //mencetak nomor loket penyerahan
    }

    //destruktor kelas DriveThru yang dipanggil otomatis saat objek dihapus dari memori
    ~DriveThru() {
        
    }
};