#include <iostream> //mengimpor pustaka iostream untuk mendukung operasi input dan output (cout, cin, endl)
#include <string>   //mengimpor pustaka string untuk menggunakan tipe data string

using namespace std; //menggunakan namespace standar agar tidak perlu menuliskan std:: pada string, cout, dan endl

//Class OnlineDelivery merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class OnlineDelivery : public MetodePemesanan {
private: // Hak akses private agar atribut hanya dapat diakses langsung dari dalam class OnlineDelivery saja
    string namaPlatform; //variabel namaPlatform bertipe string untuk menyimpan nama platform (misal: GoFood, GrabFood, ShopeeFood)
    string namaKurir; //variabel namaKurir bertipe string untuk menyimpan nama kurir pengantar
    string alamatPesanan; //variabel alamatPesanan bertipe string untuk menyimpan alamat tujuan pengiriman
    int jarakPengantaran; //variabel jarakPengantaran bertipe int untuk menyimpan jarak pengiriman dalam satuan km
    int biayaKirim; //variabel biayaKirim bertipe int untuk menyimpan ongkos kirim hasil perhitungan

public: // Hak akses public agar method dan konstruktor dapat dipanggil dari luar class
    //constructor untuk membuat object OnlineDelivery dan memanggil constructor dari superclass MetodePemesanan
    OnlineDelivery(string namaPelanggan, string waktuPemesanan, string namaPlatform, string alamatPesanan, int jarakPengantaran) 
        : MetodePemesanan(namaPelanggan, waktuPemesanan) { //memanggil konstruktor induk untuk menginisialisasi namaPelanggan dan waktuPemesanan
        this->namaPlatform = namaPlatform; //mengisi atribut namaPlatform dengan data dari parameter
        this->alamatPesanan = alamatPesanan; //mengisi atribut alamatPesanan dengan data dari parameter
        this->jarakPengantaran = jarakPengantaran; //mengisi atribut jarakPengantaran dengan data dari parameter
        this->pilihKurir(); //memanggil method pilihKurir() untuk menugaskan kurir secara otomatis
        this->hitungBiayaKirim(); //memanggil method hitungBiayaKirim() untuk menghitung ongkir awal berdasarkan jarak
    }

    //getter untuk mengambil dan mengembalikan nilai namaPlatform
    string getNamaPlatform() {
        return namaPlatform; //mengembalikan nilai dari variabel namaPlatform
    }

    //getter untuk mengambil dan mengembalikan nilai namaKurir
    string getNamaKurir() {
        return namaKurir; //mengembalikan nilai dari variabel namaKurir
    }

    //getter untuk mengambil dan mengembalikan nilai alamatPesanan
    string getAlamatPesanan() {
        return alamatPesanan; //mengembalikan nilai dari variabel alamatPesanan
    }

    //getter untuk mengambil dan mengembalikan nilai jarakPengantaran
    int getJarakPengantaran() {
        return jarakPengantaran; //mengembalikan nilai dari variabel jarakPengantaran
    }

    //getter untuk mengambil dan mengembalikan nilai biayaKirim
    int getBiayaKirim() {
        return biayaKirim; //mengembalikan nilai dari variabel biayaKirim
    }

    //setter untuk memperbarui atau mengubah data namaPlatform
    void setNamaPlatform(string namaPlatform) {
        this->namaPlatform = namaPlatform; //memperbarui nilai atribut namaPlatform
    }

    //setter untuk memperbarui atau mengubah data alamatPesanan
    void setAlamat(string alamatPesanan) {
        this->alamatPesanan = alamatPesanan; //memperbarui nilai atribut alamatPesanan
    }

    //setter untuk memperbarui jarak pengantaran dan otomatis menghitung ulang biaya kirim
    void setJarakPengantaran(int jarakPengantaran) {
        this->jarakPengantaran = jarakPengantaran; //memperbarui nilai atribut jarakPengantaran
        this->hitungBiayaKirim(); //menghitung ulang biaya kirim sesuai dengan jarak pengantaran yang baru
    }

    //untuk memilih dan menugaskan kurir secara bergantian
    void pilihKurir() {
        string daftarKurir[4] = {"Rizky", "Andi", "Lintang", "Dino"}; //array lokal berisi daftar nama kurir yang tersedia
        static int index = 0; //variabel static untuk menyimpan indeks kurir saat ini yang bertahan antar pembuatan objek
        this->namaKurir = daftarKurir[index]; //engisi atribut namaKurir berdasarkan indeks aktif saat ini
        index++; //menambahkan indeks sebanyak 1 untuk pemesanan berikutnya

        if (index >= 4) { //jika indeks melampaui batas jumlah elemen array (4 kurir)
            index = 0; //reset indeks kembali ke 0 (kurir pertama)
        }
    }

    //untuk menghitung biaya kirim berdasarkan tingkatan jarak pengantaran
    void hitungBiayaKirim() {
        if (this->jarakPengantaran <= 3) {
            this->biayaKirim = 8000; //tarif Rp8.000 jika jarak <= 3 km
        } 
        else if (this->jarakPengantaran <= 6) {
            this->biayaKirim = 10000; //tarif Rp10.000 jika jarak 4 - 6 km
        } 
        else if (this->jarakPengantaran <= 10) {
            this->biayaKirim = 12000; //tarif Rp12.000 jika jarak 7 - 10 km
        } 
        else {
            this->biayaKirim = 15000; //tarif Rp15.000 jika jarak di atas 10 km
        }
    }

    //untuk menampilkan seluruh informasi detail pemesanan layanan Online Delivery ke layar
    void tampilDelivery() {
        cout << "Metode Pemesanan   : Online Delivery" << endl; //mencetak jenis metode pemesanan ke layar
        this->tampilMetode(); //memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        cout << "Nama Platform      : " << namaPlatform << endl; //mencetak nama platform pengiriman ke layar
        cout << "Nama Kurir         : " << namaKurir << endl; //mencetak nama kurir yang ditugaskan ke layar
        cout << "Alamat Pesanan     : " << alamatPesanan << endl; //mencetak alamat pengiriman ke layar
        cout << "Jarak Pengantaran  : " << jarakPengantaran << " km" << endl; //mencetak jarak pengantaran ke layar
        cout << "Biaya Kirim        : Rp. " << biayaKirim << endl;   //mencetak total biaya kirim ke layar
    }

    //destruktor kelas OnlineDelivery yang dipanggil otomatis saat objek dihancurkan dari memori
    ~OnlineDelivery() {

    }
}; 