#include <iostream> //mengimpor pustaka iostream untuk mendukung fungsi input dan output (cout, cin, endl)
#include <string>   //mengimpor pustaka string untuk tipe data string

using namespace std; //menggunakan namespace standar agar tidak perlu menuliskan std:: pada string dan cout

//class SelfService merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class SelfService : public MetodePemesanan {
private: // Hak akses private agar atribut hanya dapat diakses langsung dari dalam class SelfService saja
    int nomorKiosk;   //variabel nomorKiosk bertipe integer untuk menyimpan mesin kiosk yang digunakan
    int nomorAntrian; //variabel nomorAntrian bertipe integer untuk menyimpan nomor antrean pelanggan

public: // Hak akses public agar method dan konstruktor dapat dipanggil dari luar class
    //constructor untuk membuat object SelfService dan memanggil constructor dari superclass MetodePemesanan
    SelfService(string namaPelanggan, string waktuPemesanan) : MetodePemesanan(namaPelanggan, waktuPemesanan) { //menginisialisasi namaPelanggan dan waktuPemesanan di kelas induk
        this->pilihKiosk(); //memanggil method pilihKiosk() untuk menentukan nomor kiosk secara otomatis
        this->ambilNomorAntrian(); //memanggil method ambilNomorAntrian() untuk menetapkan nomor antrean
    }

    //getter untuk mengambil dan mengembalikan nilai nomorKiosk
    int getNomorKiosk() {
        return nomorKiosk; //mengembalikan nilai dari variabel nomorKiosk
    }

    //getter untuk mengambil dan mengembalikan nilai nomorAntrian
    int getNomorAntrian() {
        return nomorAntrian; //mengembalikan nilai dari variabel nomorAntrian
    }

    //untuk mengalokasikan nomor kiosk secara bergantian
    void pilihKiosk() {
        static int kiosk = 1; //variabel static untuk menyimpan nomor kiosk yang nilainya bertahan selama program berjalan
        this->nomorKiosk = kiosk; //mengisi atribut nomorKiosk dengan nilai variabel kiosk saat ini
        kiosk++; //menambahkan nomor kiosk sebanyak 1 untuk pemesanan berikutnya

        if (kiosk > 4) { //jika nomor kiosk melebihi 4
            kiosk = 1; //reset nomor kiosk kembali ke angka 1
        }
    }

    //untuk mengalokasikan nomor antrean secara otomatis yang dimulai dari 101
    void ambilNomorAntrian() {
        static int antrian = 101; //variabel static untuk menyimpan nomor antrean awal (101)
        this->nomorAntrian = antrian; //mengisi atribut nomorAntrian dengan nilai antrian saat ini
        antrian++; //menambahkan nomor antrean sebanyak 1 untuk pesanan selanjutnya
    }

    //untuk menampilkan seluruh rincian informasi pemesanan Self Service ke layar
    void tampilSelfService() {
        cout << "Metode Pemesanan  : Self Service" << endl; //mencetak tipe metode pemesanan ke layar
        this->tampilMetode();                              //memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        cout << "Nomor Kiosk       : " << nomorKiosk << endl;  //mencetak nomor kiosk yang digunakan
        cout << "Nomor Antrian     : " << nomorAntrian << endl;//mencetak nomor antrean pelanggan
    }

    // Destruktor kelas SelfService yang dipanggil otomatis saat objek dihancurkan dari memori
    ~SelfService() {

    }
}; 