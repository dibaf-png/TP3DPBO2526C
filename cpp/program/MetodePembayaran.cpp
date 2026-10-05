#include <iostream> //mengimpor pustaka iostream untuk operasi input dan output data (cout, cin, endl)
#include <string>   //mengimpor pustaka string untuk pengolahan tipe data string dan fungsi to_string()

using namespace std; //menggunakan namespace standar agar tidak perlu menulis std:: di depan string, cout, dan endl

class MetodePembayaran { //membuat class bernama MetodePembayaran untuk mengelola data dan alur transaksi pembayaran
private: // Hak akses private agar atribut di bawahnya hanya dapat diakses dan diubah secara langsung dari dalam class ini
    string jenisPembayaran;  //variabel jenisPembayaran bertipe string untuk menyimpan jenis pembayaran (misal: QRIS, Transfer, Cash)
    string noPembayaran; //variabel noPembayaran bertipe string untuk menyimpan nomor transaksi/referensi unik dari sistem
    string statusPembayaran; //variabel statusPembayaran bertipe string untuk menyimpan status (Belum Dibayar / Lunas)

public: // Hak akses public agar method/fungsi di bawahnya dapat diakses dari luar class
    //constructor default untuk memberikan nilai awal (inisialisasi) pada atribut objek saat pertama kali dibuat
    MetodePembayaran() {
        this->jenisPembayaran = "-"; //mengisi nilai awal jenisPembayaran 
        this->noPembayaran = "-";//mengisi nilai awal noPembayaran 
        this->statusPembayaran = "Belum Dibayar"; //mengatur status awal pembayaran menjadi "Belum Dibayar"
    }

    //getter untuk mengambil dan mengembalikan data jenisPembayaran
    string getJenis() {
        return jenisPembayaran; //mengembalikan nilai dari variabel jenisPembayaran
    }

    //getter untuk mengambil dan mengembalikan data noPembayaran (nomor transaksi)
    string getNomor() {
        return noPembayaran; //mengembalikan nilai dari variabel noPembayaran
    }

    //getter untuk mengambil dan mengembalikan data statusPembayaran
    string getStatus() {
        return statusPembayaran; //mengembalikan nilai dari variabel statusPembayaran
    }

    //setter untuk mengubah atau menentukan jenis pembayaran (ditambahkan tipe data string pada parameter)
    void setJenis(string jenisPembayaran) {
        this->jenisPembayaran = jenisPembayaran; //memperbarui nilai atribut jenisPembayaran dengan input dari parameter
    }

    //untuk memproses pembayaran, menggenerasi nomor transaksi otomatis, dan mengubah status menjadi Lunas
    void prosesPembayaran() {
        static int noTransaksi = 1; //variabel static untuk menyimpan nomor urut transaksi yang nilainya tidak hilang selama program berjalan
        this->noPembayaran = "TRX" + to_string(noTransaksi); //membuat ID transaksi otomatis dengan gabungan teks "TRX" dan nomor urut
        noTransaksi++; //menambahkan nomor urut transaksi sebanyak 1 untuk transaksi berikutnya

        this->statusPembayaran = "Lunas"; //memperbarui nilai atribut statusPembayaran menjadi "Lunas"
    }

    //getter alternatif untuk memeriksa dan mengembalikan status pembayaran saat ini
    string cekStatus() {
        return statusPembayaran; //mengembalikan string statusPembayaran
    }

    //untuk menampilkan seluruh informasi detail pembayaran ke layar
    void tampilPembayaran() {
        cout << "Jenis Pembayaran  : " << jenisPembayaran << endl; //mencetak jenis pembayaran ke layar
        cout << "Nomor Transaksi   : " << noPembayaran << endl; //mencetak nomor transaksi ke layar (ditambahkan titik koma ;)
        cout << "Status Pembayaran : " << statusPembayaran << endl; //mencetak status pembayaran ke layar
    }

    //destruktor kelas MetodePembayaran yang dipanggil otomatis saat objek dihancurkan dari memori
    ~MetodePembayaran() {
        
    }
};