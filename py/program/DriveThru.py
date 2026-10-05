
from MetodePemesanan import MetodePemesanan

# class DriveThru merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class DriveThru(MetodePemesanan):
    # Variabel class (static) untuk menyimpan nomor loket aktif
    _loket = 1

    # constructor untuk membuat object DriveThru dan memanggil constructor dari superclass MetodePemesanan
    def __init__(self, nama_pelanggan: str, waktu_pemesanan: str, nomor_kendaraan: str, jenis_kendaraan: str,):
        super().__init__(nama_pelanggan, waktu_pemesanan)  # Memanggil konstruktor induk dengan parameter namaPelanggan dan waktu
        self._nomor_kendaraan = (nomor_kendaraan)  # mengisi atribut nomorKendaraan dengan data dari parameter nomorKendaraan
        self._jenis_kendaraan = (jenis_kendaraan)  # mengisi atribut jenisKendaraan dengan data dari parameter jenisKendaraan
        self._nomor_loket = 0  # inisialisasi atribut nomorLoket bertipe integer
        self.cek_loket()  # memanggil method cekLoket() untuk menentukan nomor loket secara otomatis saat objek dibuat

    # getter untuk mengambil dan mengembalikan nilai dari atribut nomorKendaraan
    def get_nomor_kendaraan(self) -> str:
        return (self._nomor_kendaraan)  # mengembalikan string nomorKendaraan

    # getter untuk mengambil dan mengembalikan nilai dari atribut jenisKendaraan
    def get_jenis_kendaraan(self) -> str:
        return (self._jenis_kendaraan)  # mengembalikan string jenisKendaraan

    # getter untuk mengambil dan mengembalikan nilai dari atribut nomorLoket
    def get_nomor_loket(self) -> int:
        return self._nomor_loket  # mengembalikan nilai integer nomorLoket

    # setter untuk memperbarui atau mengubah data nomorKendaraan
    def set_nomor_kendaraan(self, nomor_kendaraan: str):
        self._nomor_kendaraan = (nomor_kendaraan)  # memperbarui nilai atribut nomorKendaraan

    # setter untuk memperbarui atau mengubah data jenisKendaraan
    def set_jenis_kendaraan(self, jenis_kendaraan: str):
        self._jenis_kendaraan = (jenis_kendaraan)  # memperbarui nilai atribut jenisKendaraan

    # untuk menentukan dan mengalokasikan nomor loket secara bergantian
    def cek_loket(self):
        self._nomor_loket = (DriveThru._loket)  # mengisi atribut nomorLoket dengan nilai loket saat ini
        DriveThru._loket += (1)  # menambahkan nilai loket sebanyak 1 untuk pengalokasian berikutnya

        if DriveThru._loket > 3:  # jika nilai loket melampaui 3
            DriveThru._loket = (1)  # mengembalikan nomor loket ke angka 1

    # untuk menampilkan seluruh informasi detail pemesanan layanan Drive Thru
    def tampil_drive_thru(self):
        print("Metode Pemesanan  : Drive Thru")  # mencetak jenis metode pemesanan
        self.tampil_metode()  # memanggil method tampilMetode() milik superclass untuk mencetak ID, Nama, dan Waktu
        print(f"Nomor Kendaraan   : {self._nomor_kendaraan}")  # mencetak plat nomor kendaraan
        print(f"Jenis Kendaraan   : {self._jenis_kendaraan}")  # mencetak jenis kendaraan
        print(f"Nomor Loket       : {self._nomor_loket}")  # mencetak nomor loket penyerahan
