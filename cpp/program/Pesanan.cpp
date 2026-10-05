#include <iostream>//mengimpor pustaka iostream untuk mendukung operasi input dan output data (cout, cin, endl)
#include <string> //mengimpor pustaka string untuk pengolahan tipe data string dan to_string()
#include <vector> //mengimpor pustaka vector untuk menyimpan daftar item pesanan secara dinamis

using namespace std; //menggunakan namespace standar agar tidak perlu menuliskan std:: pada string, cout, dan vector

class Pesanan { //membuat class Pesanan untuk mengelola seluruh data transaksi, item, pembayaran, dan metode pemesanan
private: // Hak akses private agar atribut di bawah ini hanya dapat diakses langsung dari dalam class Pesanan
    string idPesanan; //variabel idPesanan bertipe string untuk menyimpan ID unik transaksi (misal: PSN1)
    int totalBayar; //variabel totalBayar bertipe int untuk menyimpan total biaya yang harus dibayar
    string statusPesanan; //variabel statusPesanan bertipe string untuk menyimpan status (Dibuat / Dibayar)
    vector<ItemPesanan> listPesanan; //variabel listPesanan berupa vector berisi objek-objek ItemPesanan
    MetodePembayaran pembayaran; //variabel atribut pembayaran berupa objek dari kelas MetodePembayaran
    MetodePemesanan* caraPemesanan; //variabel pointer caraPemesanan yang menunjuk ke objek kelas induk MetodePemesanan
    int jenisMetode; //variabel jenisMetode bertipe int sebagai penanda tipe (1: DriveThru, 2: SelfService, 3: TableService, 4: OnlineDelivery)

public: // Hak akses public agar method dan konstruktor dapat dipanggil dari luar class
    //constructor default untuk menginisialisasi nilai awal saat objek Pesanan pertama kali dibuat
    Pesanan() {
        static int noPesanan = 1; //variabel static untuk menyimpan nomor urut pesanan yang nilainya bertahan selama program berjalan
        this->idPesanan = "PSN" + to_string(noPesanan); //membuat ID unik dengan gabungan string "PSN" dan angka nomor urut
        noPesanan++; //menambahkan nilai noPesanan sebanyak 1 untuk pesanan berikutnya

        this->totalBayar = 0; //menginisialisasi totalBayar dengan angka 0
        this->statusPesanan = "Dibuat"; //mengatur status awal pesanan menjadi "Dibuat"
        this->caraPemesanan = nullptr; //mengatur pointer caraPemesanan ke nullptr (belum menunjuk objek metode pemesanan apa pun)
        this->jenisMetode = 0; //mengatur penanda jenisMetode awal ke angka 0
    }

    //getter untuk mengambil dan mengembalikan nilai idPesanan
    string getIdPesanan() {
        return idPesanan; //mengembalikan string idPesanan
    }

    //getter untuk mengambil dan mengembalikan nilai totalBayar
    int getTotalBayar() {
        return totalBayar; //mengembalikan nilai totalBayar
    }

    //getter untuk mengambil dan mengembalikan nilai statusPesanan
    string getStatusPesanan() {
        return statusPesanan; //mengembalikan string statusPesanan
    }

    //getter untuk mengambil dan mengembalikan angka kode jenisMetode
    int getJenisMetode() {
        return jenisMetode; //mengembalikan angka jenisMetode
    }

    //getter untuk mengambil dan mengembalikan pointer objek caraPemesanan
    MetodePemesanan* getCaraPemesanan() {
        return caraPemesanan; //mengembalikan pointer caraPemesanan
    }

    //getter untuk mengambil dan mengembalikan objek pembayaran
    MetodePembayaran getPembayaran() {
        return pembayaran; //mengembalikan objek pembayaran
    }

    //setter untuk mengatur pointer metode pemesanan dan menandai jenis metodenya
    void setCaraPemesanan(MetodePemesanan* caraPemesanan, int jenisMetode) {
        this->caraPemesanan = caraPemesanan; //mengarahkan pointer caraPemesanan ke alamat objek metode pemesanan yang dikirim
        this->jenisMetode = jenisMetode;     //mengisi angka penanda jenisMetode sesuai input parameter
    }

    //untuk menambahkan objek ItemPesanan baru ke dalam vector listPesanan
    void tambahPesanan(ItemPesanan item) {
        this->listPesanan.push_back(item); //memasukkan objek item ke urutan terakhir pada vector listPesanan
    }

    //untuk menghitung total biaya keseluruhan pesanan (subtotal item + biaya kirim)
    void hitungTotal(int biayaKirim = 0) {
        this->totalBayar = biayaKirim; //mengeset totalBayar awal dengan nilai biaya kirim (default: 0)

        // Perulangan untuk menjumlahkan subtotal dari seluruh item yang ada di vector listPesanan
        for (size_t i = 0; i < this->listPesanan.size(); i++) {
            this->totalBayar += this->listPesanan[i].hitungSubtotal(); //menambahkan subtotal item ke totalBayar
        }
    }

    //untuk menentukan jenis metode pembayaran pada objek pembayaran
    void setJenisPembayaran(string jenis) {
        this->pembayaran.setJenis(jenis); //memanggil setJenis() milik objek pembayaran
    }

    //untuk memproses pembayaran dan mengubah status pesanan menjadi Dibayar
    void bayarPesanan() {
        this->pembayaran.prosesPembayaran(); //memanggil prosesPembayaran() milik objek pembayaran untuk mendapatkan nomor transaksi
        this->statusPesanan = "Dibayar";    //mengubah status pesanan menjadi "Dibayar"
    }

    //untuk menampilkan seluruh detail rincian data pesanan ke layar
    void tampilPesanan() {
        cout << endl; //mencetak baris baru untuk kerapian tampilan
        cout << "        <<<<<<<<<< DATA PESANAN >>>>>>>>>>" << endl; //mencetak judul header
        cout << "ID Pesanan       : " << this->idPesanan << endl; //mencetak ID pesanan 
        cout << "Status Pesanan   : " << this->statusPesanan << endl; //mencetak status pesanan ke layar

        cout << endl; //mencetak baris baru

        //memeriksa apakah pointer caraPemesanan tidak kosong (menunjuk ke salah satu objek metode pemesanan)
        if (this->caraPemesanan != nullptr) {
            this->caraPemesanan->tampilMetode(); //memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu

            //pengecekan jika jenisMetode bernilai 1 (Drive Thru)
            if (this->jenisMetode == 1) {
                //konversi pointer induk ke pointer DriveThru dengan static_cast
                DriveThru* dataDriveThru = static_cast<DriveThru*>(this->caraPemesanan);

                //mencetak rincian khusus layanan Drive Thru
                cout << "Metode Pemesanan : Drive Thru" << endl;
                cout << "Nomor Kendaraan  : " << dataDriveThru->getNomorKendaraan() << endl; //mencetak plat nomor kendaraan
                cout << "Jenis Kendaraan  : " << dataDriveThru->getJenisKendaraan() << endl; //mencetak jenis kendaraan
                cout << "Nomor Loket      : " << dataDriveThru->getNomorLoket() << endl; //mencetak nomor loket
            }
            //pengecekan jika jenisMetode bernilai 2 (Self Service)
            else if (this->jenisMetode == 2) {
                //konversi pointer induk ke pointer SelfService dengan static_cast
                SelfService* dataSelfService = static_cast<SelfService*>(this->caraPemesanan);

                //mencetak rincian khusus layanan Self Service
                cout << "Metode Pemesanan : Self Service" << endl;
                cout << "Nomor Kiosk      : " << dataSelfService->getNomorKiosk() << endl; //mencetak nomor kiosk
                cout << "Nomor Antrian    : " << dataSelfService->getNomorAntrian() << endl; //mencetak nomor antrean
            }
            //pengecekan jika jenisMetode bernilai 3 (Table Service)
            else if (this->jenisMetode == 3) {
                //konversi pointer induk ke pointer TableService dengan static_cast
                TableService* dataTableService = static_cast<TableService*>(this->caraPemesanan);

                //mencetak rincian khusus layanan Table Service
                cout << "Metode Pemesanan : Table Service" << endl;
                cout << "Nomor Meja       : " << dataTableService->getNomorMeja() << endl; //mencetak nomor meja
                cout << "Jumlah Pelanggan : " << dataTableService->getJumlahPelanggan() << endl; //mencetak jumlah pelanggan
                cout << "Nama Pelayan     : " << dataTableService->getNamaPelayan() << endl; //mencetak nama pelayan
            }
            //pengecekan jika jenisMetode bernilai 4 (Online Delivery)
            else if (this->jenisMetode == 4) {
                //konversi pointer induk ke pointer OnlineDelivery dengan static_cast
                OnlineDelivery* dataOnlineDelivery = static_cast<OnlineDelivery*>(this->caraPemesanan);

                //mencetak rincian khusus layanan Online Delivery
                cout << "Metode Pemesanan : Online Delivery" << endl;
                cout << "Platform         : " << dataOnlineDelivery->getNamaPlatform() << endl;     //mencetak nama platform
                cout << "Nama Kurir       : " << dataOnlineDelivery->getNamaKurir() << endl;        //mencetak nama kurir
                cout << "Alamat           : " << dataOnlineDelivery->getAlamatPesanan() << endl;    //mencetak alamat pengiriman
                cout << "Jarak            : " << dataOnlineDelivery->getJarakPengantaran() << " km" << endl; //mencetak jarak
                cout << "Biaya Kirim      : Rp." << dataOnlineDelivery->getBiayaKirim() << endl;   //mencetak biaya kirim
            }
        }

        cout << endl; //mencetak baris baru
        cout << "Daftar Pesanan:" << endl; //mencetak header daftar item pesanan

        // Perulangan untuk mencetak seluruh item pesanan dari vector listPesanan secara ringkas 1 baris
for (size_t i = 0; i < this->listPesanan.size(); i++) {
    ItemPesanan item = this->listPesanan[i]; // mengambil objek ItemPesanan dari vector pada indeks i
    cout << i + 1 << ". " << item.getNamaProduk() 
         << " (x" << item.getJumlah() << ")"
         << " | @ Rp." << item.getHarga() 
         << " = Rp." << item.hitungSubtotal() << endl; // mencetak rincian item dalam 1 baris
}

        //memanggil method untuk menampilkan detail nomor transaksi dan status pembayaran
        this->pembayaran.tampilPembayaran();

        //menginisialisasi variabel lokal subtotal dengan nilai 0 untuk menghitung murni harga makanan/minuman
        int subtotal = 0;

        //perulangan untuk menghitung akumulasi total subtotal dari semua item pesanan
        for (size_t i = 0; i < this->listPesanan.size(); i++) {
            subtotal += this->listPesanan[i].hitungSubtotal(); //mengakumulasikan subtotal item
        }

        cout << endl; //mencetak baris baru
        cout << "Subtotal Pesanan : Rp." << subtotal << endl; //mencetak total harga makanan/minuman tanpa ongkir

        int biayaKirim = 0; // Deklarasi variabel lokal biayaKirim dengan nilai awal 0

        // Memeriksa jika jenisMetode adalah Online Delivery (4) untuk mengambil biaya kirim
        if (this->jenisMetode == 4) {
            OnlineDelivery* dataOnlineDelivery = static_cast<OnlineDelivery*>(this->caraPemesanan); // Konversi pointer
            biayaKirim = dataOnlineDelivery->getBiayaKirim(); // Mengambil nilai biaya kirim dari objek OnlineDelivery
        }

        cout << "Biaya Kirim      : Rp." << biayaKirim << endl;    //mencetak biaya kirim ke layar
        cout << "Total Bayar      : Rp." << this->totalBayar << endl; //mencetak total pembayaran akhir ke layar
        cout << "==================================================" << endl; //mencetak garis penutup
    }

    // Destruktor kelas Pesanan yang dipanggil otomatis saat objek dihapus dari memori
    ~Pesanan() {
        
    }
};