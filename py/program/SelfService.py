from MetodePemesanan import MetodePemesanan

# class SelfService merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class SelfService(MetodePemesanan):
    # Variabel class (static) untuk menyimpan state kiosk dan antrean aktif
    _kiosk = 1
    _antrian = 101

    # constructor untuk membuat object SelfService dan memanggil constructor dari superclass MetodePemesanan
    def __init__(self, nama_pelanggan: str, waktu_pemesanan: str):
        super().__init__(nama_pelanggan, waktu_pemesanan)  # menginisialisasi namaPelanggan dan waktuPemesanan di kelas induk
        self._nomor_kiosk = 0  # inisialisasi atribut nomorKiosk bertipe integer
        self._nomor_antrian = (0)  # inisialisasi atribut nomorAntrian bertipe integer

        self.pilih_kiosk()  # memanggil method pilihKiosk() untuk menentukan nomor kiosk secara otomatis
        self.ambil_nomor_antrian()  # memanggil method ambilNomorAntrian() untuk menetapkan nomor antrean

    # getter untuk mengambil dan mengembalikan nilai nomorKiosk
    def get_nomor_kiosk(self) -> int:
        return self._nomor_kiosk  # mengembalikan nilai dari variabel nomorKiosk

    # getter untuk mengambil dan mengembalikan nilai nomorAntrian
    def get_nomor_antrian(self) -> int:
        return (self._nomor_antrian)  # mengembalikan nilai dari variabel nomorAntrian

    # untuk mengalokasikan nomor kiosk secara bergantian
    def pilih_kiosk(self):
        self._nomor_kiosk = (SelfService._kiosk)  # mengisi atribut nomorKiosk dengan nilai variabel kiosk saat ini
        SelfService._kiosk += (1)  # menambahkan nomor kiosk sebanyak 1 untuk pemesanan berikutnya

        if SelfService._kiosk > 4:  # jika nomor kiosk melebihi 4
            SelfService._kiosk = 1  # reset nomor kiosk kembali ke angka 1

    # untuk mengalokasikan nomor antrean secara otomatis yang dimulai dari 101
    def ambil_nomor_antrian(self):
        self._nomor_antrian = (SelfService._antrian)  # mengisi atribut nomorAntrian dengan nilai antrian saat ini
        SelfService._antrian += (1)  # menambahkan nomor antrean sebanyak 1 untuk pesanan selanjutnya

    # untuk menampilkan seluruh rincian informasi pemesanan Self Service ke layar
    def tampil_self_service(self):
        print("Metode Pemesanan  : Self Service")  # mencetak tipe metode pemesanan ke layar
        self.tampil_metode()  # memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        print(f"Nomor Kiosk       : {self._nomor_kiosk}")  # mencetak nomor kiosk yang digunakan
        print(f"Nomor Antrian     : {self._nomor_antrian}")  # mencetak nomor antrean pelanggan
