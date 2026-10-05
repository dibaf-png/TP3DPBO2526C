class MetodePemesanan:  # membuat class bernama MetodePemesanan
    # Variabel class (static) untuk menyimpan nomor urut metode yang nilainya bertahan selama program berjalan
    _no_metode = 1

    # Constructor (__init__) untuk membuat object MetodePemesanan
    def __init__(self, nama_pelanggan: str, waktu_pemesanan: str):
        # Membuat ID unik dengan menggabungkan teks "MD" dan angka nomor urut
        self._id_metode = f"MD{MetodePemesanan._no_metode}"
        # Menambahkan nilai _no_metode sebanyak 1 secara otomatis untuk pembuatan objek berikutnya
        MetodePemesanan._no_metode += 1

        # Mengisi atribut nama_pelanggan milik kelas dengan data dari parameter
        self._nama_pelanggan = nama_pelanggan
        # Mengisi atribut waktu_pemesanan milik kelas dengan data dari parameter
        self._waktu_pemesanan = waktu_pemesanan

    # Getter untuk mengambil dan mengembalikan nilai idMetode
    def get_id_metode(self) -> str:
        return self._id_metode  # mengembalikan nilai dari variabel id_metode ke pemanggil fungsi

    # Getter untuk mengambil dan mengembalikan nilai namaPelanggan
    def get_nama(self) -> str:
        return self._nama_pelanggan  # mengembalikan nilai dari variabel nama_pelanggan ke pemanggil fungsi

    # Getter untuk mengambil dan mengembalikan nilai waktuPemesanan
    def get_waktu(self) -> str:
        return self._waktu_pemesanan  # mengembalikan nilai dari variabel waktu_pemesanan ke pemanggil fungsi

    # Setter untuk memperbarui atau mengubah data namaPelanggan
    def set_nama(self, nama_pelanggan: str):
        self._nama_pelanggan = nama_pelanggan  # memperbarui nilai atribut nama_pelanggan dengan nilai baru dari parameter

    # Setter untuk memperbarui atau mengubah data waktuPemesanan
    def set_waktu(self, waktu_pemesanan: str):
        self._waktu_pemesanan = waktu_pemesanan  # memperbarui nilai atribut waktu_pemesanan dengan nilai baru dari parameter

    # Untuk menampilkan seluruh data informasi metode pemesanan ke layar
    def tampil_metode(self):
        print(f"ID Metode        : {self._id_metode}")  # mencetak ID metode ke layar terminal
        print(f"Nama Pelanggan   : {self._nama_pelanggan}")  # mencetak nama pelanggan ke layar terminal
        print(f"Waktu Pemesanan  : {self._waktu_pemesanan}")  # mencetak waktu pemesanan ke layar terminal