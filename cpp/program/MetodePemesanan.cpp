#include <iostream> //mengimpor pustaka iostream untuk mendukung fungsi input dan output standar seperti cout dan cin
#include <string>   //mengimpor pustaka string untuk menggunakan tipe data string dan fungsi to_string()

using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: sebelum cout, cin, atau string

class MetodePemesanan { //mmebuat class bernama MetodePemesanan
protected: // Hak akses protected agar atribut di bawahnya dapat diakses oleh kelas ini dan kelas turunannya
    string idMetode;  //variabel idMetode bertipe string untuk menyimpan identitas unik metode pemesanan
    string namaPelanggan;  //variabel namaPelanggan bertipe string untuk menyimpan nama pemesan
    string waktuPemesanan; //variabel waktuPemesanan bertipe string untuk menyimpan data waktu pemesanan

public: // Hak akses public agar fungsi/method di bawahnya dapat dipanggil dan diakses dari luar kelas
    //constructor untuk membuat object MetodePemesanan
    MetodePemesanan(string namaPelanggan, string waktuPemesanan) {
        static int noMetode = 1; //variabel static untuk menyimpan nomor urut metode yang nilainya bertahan selama program berjalan
        this->idMetode = "MD" + to_string(noMetode); //membuat ID unik dengan menggabungkan teks "MD" dan angka nomor urut
        noMetode++; //menambahkan nilai noMetode sebanyak 1 secara otomatis untuk pembuatan objek berikutnya

        this->namaPelanggan = namaPelanggan; //mengisi atribut namaPelanggan milik kelas dengan data dari parameter
        this->waktuPemesanan = waktuPemesanan; //mengisi atribut waktuPemesanan milik kelas dengan data dari parameter
    }

    //getter untuk mengambil dan mengembalikan nilai idMetode
    string getIdMetode() {
        return idMetode; //mengembalikan nilai dari variabel idMetode ke pemanggil fungsi
    }

    //getter untuk mengambil dan mengembalikan nilai namaPelanggan
    string getNama() {
        return namaPelanggan; //mengembalikan nilai dari variabel namaPelanggan ke pemanggil fungsi
    }

    //getter untuk mengambil dan mengembalikan nilai waktuPemesanan
    string getWaktu() {
        return waktuPemesanan; //mengembalikan nilai dari variabel waktuPemesanan ke pemanggil fungsi
    }

    //setter untuk memperbarui atau mengubah data namaPelanggan
    void setNama(string namaPelanggan) {
        this->namaPelanggan = namaPelanggan; //memperbarui nilai atribut namaPelanggan dengan nilai baru dari parameter
    }

    //setter untuk memperbarui atau mengubah data waktuPemesanan
    void setWaktu(string waktuPemesanan) {
        this->waktuPemesanan = waktuPemesanan; //memperbarui nilai atribut waktuPemesanan dengan nilai baru dari parameter
    }

    //untuk menampilkan seluruh data informasi metode pemesanan ke layar
    void tampilMetode() {
        cout << "ID Metode        : " << idMetode << endl;//mencetak ID metode ke layar terminal
        cout << "Nama Pelanggan   : " << namaPelanggan << endl;  //mencetak nama pelanggan ke layar terminal
        cout << "Waktu Pemesanan  : " << waktuPemesanan << endl; //mencetak waktu pemesanan ke layar terminal
    }

    // Destruktor kelas MetodePemesanan yang dipanggil saat objek dihancurkan dari memori
    ~MetodePemesanan() {
        
    }
};