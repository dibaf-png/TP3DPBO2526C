#include <iostream> //mengimpor pustaka iostream untuk mendukung operasi input dan output seperti cout dan cin
#include <string>   //mengimpor pustaka string untuk menggunakan tipe data string

using namespace std; //menggunakan namespace standar agar tidak perlu menulis std:: sebelum string, cout, atau endl

class ItemPesanan { //membuat class bernama ItemPesanan untuk mengelola data tiap produk yang dipesan
private: // Hak akses private agar atribut di bawahnya hanya dapat diakses dari dalam class ini sendiri
    string namaProduk; //variabel namaProduk bertipe string untuk menyimpan nama produk
    int hargaProduk; //variabel hargaProduk bertipe int untuk menyimpan harga satuan produk
    int jumlahProduk; //variabel jumlahProduk bertipe int untuk menyimpan jumlah produk yang dipesan

public: // Hak akses public agar method di bawahnya dapat diakses dan dipanggil dari luar class
    //constructor untuk menginisialisasi objek ItemPesanan saat dibuat
    ItemPesanan(string namaProduk, int hargaProduk, int jumlahProduk) {
        this->namaProduk = namaProduk;   //mengisi atribut namaProduk dengan nilai dari parameter namaProduk
        this->hargaProduk = hargaProduk; //mengisi atribut hargaProduk dengan nilai dari parameter hargaProduk
        this->jumlahProduk = jumlahProduk; //mengisi atribut jumlahProduk dengan nilai dari parameter jumlahProduk
    }

    //getter untuk mengambil dan mengembalikan nilai namaProduk
    string getNamaProduk() {
        return namaProduk; //mengembalikan nilai dari variabel namaProduk
    }

    //getter untuk mengambil dan mengembalikan nilai hargaProduk
    int getHarga() {
        return hargaProduk; //mengembalikan nilai dari variabel hargaProduk
    }

    //getter untuk mengambil dan mengembalikan nilai jumlahProduk
    int getJumlah() {
        return jumlahProduk; //mengembalikan nilai dari variabel jumlahProduk
    }

    //setter untuk memperbarui atau mengubah nilai namaProduk
    void setNamaProduk(string namaProduk) {
        this->namaProduk = namaProduk; //memperbarui nilai atribut namaProduk dengan data baru dari parameter
    }

    //setter untuk memperbarui atau mengubah nilai jumlahProduk
    void setJumlah(int jumlahProduk) {
        this->jumlahProduk = jumlahProduk; //memperbarui nilai atribut jumlahProduk dengan data baru dari parameter
    }

    //untuk mengubah kuantitas/jumlah produk (fungsi operasional)
    void ubahJumlahProduk(int jumlahProduk) {
        this->jumlahProduk = jumlahProduk; //memperbarui jumlah produk yang dipesan
    }

    //untuk menghitung total harga item (harga * jumlah)
    int hitungSubtotal() {
        return hargaProduk * jumlahProduk; //mengembalikan hasil perkalian antara hargaProduk dan jumlahProduk
    }

    //untuk menampilkan seluruh detail rincian produk ke layar
    void tampilItem() {
        cout << "Nama Produk   : " << namaProduk << endl;         // Mencetak nama produk ke layar
        cout << "Harga Produk  : " << hargaProduk << endl;        // Mencetak harga satuan produk ke layar
        cout << "Jumlah Produk : " << jumlahProduk << endl;       // Mencetak jumlah item yang dipesan ke layar
        cout << "Subtotal      : " << hitungSubtotal() << endl;   // Mencetak subtotal harga produk (ditambahkan kurung ())
    }

    // Destruktor kelas ItemPesanan yang dipanggil otomatis saat objek dihapus dari memori
    ~ItemPesanan() {
        
    }
}; 