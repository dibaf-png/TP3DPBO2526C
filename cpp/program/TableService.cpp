#include <iostream> //mengimpor pustaka iostream untuk mendukung fungsi input dan output (cout, cin, endl)
#include <string>   //mengimpor pustaka string untuk menggunakan tipe data string

using namespace std; //menggunakan namespace standar agar tidak perlu menuliskan std:: pada string, cout, dan endl

//class TableService merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class TableService : public MetodePemesanan {
private: // Hak akses private agar atribut hanya dapat diakses langsung dari dalam class TableService ini sendiri
    int nomorMeja; //variabel nomorMeja bertipe int untuk menyimpan nomor meja pelanggan
    int jumlahPelanggan; //variabel jumlahPelanggan bertipe int untuk menyimpan jumlah orang dalam pemesanan
    string namaPelayan;  //variabel namaPelayan bertipe string untuk menyimpan nama pelayan yang bertugas

public: // Hak akses public agar method dan konstruktor dapat dipanggil dari luar class
    //constructor untuk membuat object TableService dan memanggil constructor dari superclass MetodePemesanan
    TableService(string namaPelanggan, string waktuPemesanan, int jumlahPelanggan) : MetodePemesanan(namaPelanggan, waktuPemesanan) { //memanggil konstruktor induk untuk mengisi namaPelanggan dan waktuPemesanan
        this->jumlahPelanggan = jumlahPelanggan; //mengisi atribut jumlahPelanggan dengan data dari parameter
        this->pilihMeja(); //memanggil method pilihMeja() untuk mengalokasikan nomor meja secara otomatis
        this->pilihPelayan(); //memanggil method pilihPelayan() untuk menugaskan pelayan secara otomatis
    }

    //getter untuk mengambil dan mengembalikan nilai dari atribut nomorMeja
    int getNomorMeja() {
        return nomorMeja; //mengembalikan nilai dari variabel nomorMeja
    }

    //getter untuk mengambil dan mengembalikan nilai dari atribut jumlahPelanggan
    int getJumlahPelanggan() {
        return jumlahPelanggan; //mengembalikan nilai dari variabel jumlahPelanggan
    }

    //getter untuk mengambil dan mengembalikan nilai dari atribut namaPelayan
    string getNamaPelayan() {
        return namaPelayan; //mengembalikan nilai dari variabel namaPelayan
    }

    //setter untuk memperbarui atau mengubah data jumlahPelanggan
    void setJumlahPelanggan(int jumlahPelanggan) {
        this->jumlahPelanggan = jumlahPelanggan; //memperbarui nilai atribut jumlahPelanggan dengan data dari parameter
    }

    //untuk memilih nomor meja secara otomatis (siklus Meja 1 hingga Meja 10)
    void pilihMeja() {
        static int meja = 1; //variabel static untuk menyimpan nomor meja yang nilainya bertahan antar pembuatan objek
        this->nomorMeja = meja;  //mengisi atribut nomorMeja dengan nilai variabel meja saat ini
        meja++; //menambahkan nomor meja sebanyak 1 untuk pemesanan berikutnya

        if (meja > 10) { //jika nomor meja melebihi 10
            meja = 1; //reset nomor meja kembali ke angka 1
        }
    }

    //untuk memilih dan menugaskan pelayan secara bergantian
    void pilihPelayan() {
        string daftarPelayan[4] = {"Eka", "Yuni", "Milo", "Tian"}; //array lokal berisi daftar nama pelayan yang tersedia
        static int index = 0;   //variabel static untuk menyimpan indeks array pelayan saat ini
        this->namaPelayan = daftarPelayan[index]; //mengisi atribut namaPelayan berdasarkan indeks aktif
        index++; //menambahkan indeks sebanyak 1 untuk pemesanan berikutnya

        if (index >= 4) { //jika indeks melampaui batas jumlah elemen array (4 pelayan)
            index = 0; //reset indeks kembali ke 0 (pelayan pertama)
        }
    }

    //untuk menampilkan seluruh informasi detail pemesanan layanan Table Service ke layar
    void tampilTableService() {
        cout << "Metode Pemesanan : Table Service" << endl; //mencetak jenis metode pemesanan ke layar
        this->tampilMetode(); //memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        cout << "Nomor Meja       : " << nomorMeja << endl; //mencetak nomor meja yang dialokasikan
        cout << "Jumlah Pelanggan : " << jumlahPelanggan << endl; //mencetak jumlah pelanggan yang datang
        cout << "Nama Pelayan     : " << namaPelayan << endl; //mencetak nama pelayan yang melayani
    }

    //destruktor kelas TableService yang dipanggil otomatis saat objek dihancurkan dari memori
    ~TableService() {

    }
}; 