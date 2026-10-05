from MetodePemesanan import MetodePemesanan

# Class OnlineDelivery merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class OnlineDelivery(MetodePemesanan):
    # Variabel class (static) untuk menyimpan state indeks kurir aktif
    _index_kurir = 0

    # constructor untuk membuat object OnlineDelivery dan memanggil constructor dari superclass MetodePemesanan
    def __init__(self, nama_pelanggan: str, waktu_pemesanan: str, nama_platform: str, alamat_pesanan: str, jarak_pengantaran: int):
        super().__init__(nama_pelanggan, waktu_pemesanan)  # memanggil konstruktor induk untuk menginisialisasi namaPelanggan dan waktuPemesanan
        self._nama_platform = (nama_platform)  # mengisi atribut namaPlatform dengan data dari parameter
        self._alamat_pesanan = (alamat_pesanan)  # mengisi atribut alamatPesanan dengan data dari parameter
        self._jarak_pengantaran = (jarak_pengantaran)  # mengisi atribut jarakPengantaran dengan data dari parameter
    
        self._nama_kurir = ""  # inisialisasi atribut namaKurir bertipe string
        self._biaya_kirim = 0  # inisialisasi atribut biayaKirim bertipe integer

        self.pilih_kurir()  # memanggil method pilihKurir() untuk menugaskan kurir secara otomatis
        self.hitung_biaya_kirim()  # memanggil method hitungBiayaKirim() untuk menghitung ongkir awal berdasarkan jarak

    # getter untuk mengambil dan mengembalikan nilai namaPlatform
    def get_nama_platform(self) -> str:
        return (self._nama_platform)  # mengembalikan nilai dari variabel namaPlatform

    # getter untuk mengambil dan mengembalikan nilai namaKurir
    def get_nama_kurir(self) -> str:
        return self._nama_kurir  # mengembalikan nilai dari variabel namaKurir

    # getter untuk mengambil dan mengembalikan nilai alamatPesanan
    def get_alamat_pesanan(self) -> str:
        return (self._alamat_pesanan)  # mengembalikan nilai dari variabel alamatPesanan

    # getter untuk mengambil dan mengembalikan nilai jarakPengantaran
    def get_jarak_pengantaran(self) -> int:
        return (self._jarak_pengantaran)  # mengembalikan nilai dari variabel jarakPengantaran

    # getter untuk mengambil dan mengembalikan nilai biayaKirim
    def get_biaya_kirim(self) -> int:
        return self._biaya_kirim  # mengembalikan nilai dari variabel biayaKirim

    # setter untuk memperbarui atau mengubah data namaPlatform
    def set_nama_platform(self, nama_platform: str):
        self._nama_platform = (nama_platform)  # memperbarui nilai atribut namaPlatform

    # setter untuk memperbarui atau mengubah data alamatPesanan
    def set_alamat(self, alamat_pesanan: str):
        self._alamat_pesanan = (alamat_pesanan)  # memperbarui nilai atribut alamatPesanan

    # setter untuk memperbarui jarak pengantaran dan otomatis menghitung ulang biaya kirim
    def set_jarak_pengantaran(self, jarak_pengantaran: int):
        self._jarak_pengantaran = (jarak_pengantaran)  # memperbarui nilai atribut jarakPengantaran
        self.hitung_biaya_kirim()  # menghitung ulang biaya kirim sesuai dengan jarak pengantaran yang baru

    # untuk memilih dan menugaskan kurir secara bergantian
    def pilih_kurir(self):
        daftar_kurir = ["Rizky", "Andi", "Lintang", "Dino",]  # array/list lokal berisi daftar nama kurir yang tersedia
        self._nama_kurir = daftar_kurir[OnlineDelivery._index_kurir]  # mengisi atribut namaKurir berdasarkan indeks aktif saat ini
        OnlineDelivery._index_kurir += (1)  # menambahkan indeks sebanyak 1 untuk pemesanan berikutnya

        if (OnlineDelivery._index_kurir >= 4):  # jika indeks melampaui batas jumlah elemen array (4 kurir)
            OnlineDelivery._index_kurir = (0)  # reset indeks kembali ke 0 (kurir pertama)

    # untuk menghitung biaya kirim berdasarkan tingkatan jarak pengantaran
    def hitung_biaya_kirim(self):
        if self._jarak_pengantaran <= 3:
            self._biaya_kirim = 8000  # tarif Rp8.000 jika jarak <= 3 km
        elif self._jarak_pengantaran <= 6:
            self._biaya_kirim = 10000  # tarif Rp10.000 jika jarak 4 - 6 km
        elif self._jarak_pengantaran <= 10:
            self._biaya_kirim = 12000  # tarif Rp12.000 jika jarak 7 - 10 km
        else:
            self._biaya_kirim = (15000)  # tarif Rp15.000 jika jarak di atas 10 km

    # untuk menampilkan seluruh informasi detail pemesanan layanan Online Delivery ke layar
    def tampil_delivery(self):
        print("Metode Pemesanan   : Online Delivery")  # mencetak jenis metode pemesanan ke layar
        self.tampil_metode()  # memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        print(f"Nama Platform      : {self._nama_platform}")  # mencetak nama platform pengiriman ke layar
        print(f"Nama Kurir         : {self._nama_kurir}")  # mencetak nama kurir yang ditugaskan ke layar
        print(f"Alamat Pesanan     : {self._alamat_pesanan}")  # mencetak alamat pengiriman ke layar
        print(f"Jarak Pengantaran  : {self._jarak_pengantaran} km")  # mencetak jarak pengantaran ke layar
        print(f"Biaya Kirim        : Rp. {self._biaya_kirim}")  # mencetak total biaya kirim ke layar