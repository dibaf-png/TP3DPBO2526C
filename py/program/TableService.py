from MetodePemesanan import MetodePemesanan

# class TableService merupakan subclass yang mewarisi (inheritance) atribut dan method dari superclass MetodePemesanan
class TableService(MetodePemesanan):
    # Variabel class (static) untuk menyimpan state meja dan indeks pelayan aktif
    _meja = 1
    _index_pelayan = 0

    # constructor untuk membuat object TableService dan memanggil constructor dari superclass MetodePemesanan
    def __init__(self, nama_pelanggan: str, waktu_pemesanan: str, jumlah_pelanggan: int):
        super().__init__(nama_pelanggan, waktu_pemesanan)  # memanggil konstruktor induk untuk mengisi namaPelanggan dan waktuPemesanan
        self._jumlah_pelanggan = (jumlah_pelanggan)  # mengisi atribut jumlahPelanggan dengan data dari parameter
        self._nomor_meja = 0  # inisialisasi atribut nomorMeja bertipe integer
        self._nama_pelayan = ("")  # inisialisasi atribut namaPelayan bertipe string

        self.pilih_meja()  # memanggil method pilihMeja() untuk mengalokasikan nomor meja secara otomatis
        self.pilih_pelayan()  # memanggil method pilihPelayan() untuk menugaskan pelayan secara otomatis

    # getter untuk mengambil dan mengembalikan nilai dari atribut nomorMeja
    def get_nomor_meja(self) -> int:
        return self._nomor_meja  # mengembalikan nilai dari variabel nomorMeja

    # getter untuk mengambil dan mengembalikan nilai dari atribut jumlahPelanggan
    def get_jumlah_pelanggan(self) -> int:
        return (self._jumlah_pelanggan)  # mengembalikan nilai dari variabel jumlahPelanggan

    # getter untuk mengambil dan mengembalikan nilai dari atribut namaPelayan
    def get_nama_pelayan(self) -> str:
        return (self._nama_pelayan)  # mengembalikan nilai dari variabel namaPelayan

    # setter untuk memperbarui atau mengubah data jumlahPelanggan
    def set_jumlah_pelanggan(self, jumlah_pelanggan: int):
        self._jumlah_pelanggan = (jumlah_pelanggan)  # memperbarui nilai atribut jumlahPelanggan dengan data dari parameter

    # untuk memilih nomor meja secara otomatis (siklus Meja 1 hingga Meja 10)
    def pilih_meja(self):
        self._nomor_meja = (TableService._meja)  # mengisi atribut nomorMeja dengan nilai variabel meja saat ini
        TableService._meja += (1)  # menambahkan nomor meja sebanyak 1 untuk pemesanan berikutnya

        if TableService._meja > 10:  # jika nomor meja melebihi 10
            TableService._meja = 1  # reset nomor meja kembali ke angka 1

    # untuk memilih dan menugaskan pelayan secara bergantian
    def pilih_pelayan(self):
        daftar_pelayan = ["Eka", "Yuni", "Milo", "Tian",]  # array/list lokal berisi daftar nama pelayan yang tersedia
        self._nama_pelayan = daftar_pelayan[TableService._index_pelayan]  # mengisi atribut namaPelayan berdasarkan indeks aktif
        TableService._index_pelayan += (1)  # menambahkan indeks sebanyak 1 untuk pemesanan berikutnya

        if (TableService._index_pelayan >= 4):  # jika indeks melampaui batas jumlah elemen array (4 pelayan)
            TableService._index_pelayan = (0)  # reset indeks kembali ke 0 (pelayan pertama)

    # untuk menampilkan seluruh informasi detail pemesanan layanan Table Service ke layar
    def tampil_table_service(self):
        print("Metode Pemesanan : Table Service")  # mencetak jenis metode pemesanan ke layar
        self.tampil_metode()  # memanggil method tampilMetode() milik kelas induk untuk mencetak ID, Nama, dan Waktu
        print(f"Nomor Meja        : {self._nomor_meja}")  # mencetak nomor meja yang dialokasikan
        print(f"Jumlah Pelanggan : {self._jumlah_pelanggan}")  # mencetak jumlah pelanggan yang datang
        print(f"Nama Pelayan     : {self._nama_pelayan}")  # mencetak nama pelayan yang melayani