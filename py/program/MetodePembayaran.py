class MetodePembayaran:  # membuat class bernama MetodePembayaran untuk mengelola data dan alur transaksi pembayaran
    # Variabel class (static) untuk menyimpan nomor urut transaksi yang nilainya tidak hilang selama program berjalan
    _no_transaksi = 1

    # Constructor (__init__) default untuk memberikan nilai awal (inisialisasi) pada atribut objek saat pertama kali dibuat
    def __init__(self):
        self._jenis_pembayaran = ("-")  # mengisi nilai awal jenis_pembayaran
        self._no_pembayaran = "-"  # mengisi nilai awal no_pembayaran
        self._status_pembayaran = ("Belum Dibayar")  # mengatur status awal pembayaran menjadi "Belum Dibayar"

    # getter untuk mengambil dan mengembalikan data jenisPembayaran
    def get_jenis(self) -> str:
        return self._jenis_pembayaran  # mengembalikan nilai dari variabel jenis_pembayaran

    # getter untuk mengambil dan mengembalikan data noPembayaran (nomor transaksi)
    def get_nomor(self) -> str:
        return self._no_pembayaran  # mengembalikan nilai dari variabel no_pembayaran

    # getter untuk mengambil dan mengembalikan data statusPembayaran
    def get_status(self) -> str:
        return self._status_pembayaran  # mengembalikan nilai dari variabel status_pembayaran

    # setter untuk mengubah atau menentukan jenis pembayaran
    def set_jenis(self, jenis_pembayaran: str):
        self._jenis_pembayaran = (jenis_pembayaran)  # memperbarui nilai atribut jenis_pembayaran dengan input dari parameter

    # untuk memproses pembayaran, menggenerasi nomor transaksi otomatis, dan mengubah status menjadi Lunas
    def proses_pembayaran(self):
        # membuat ID transaksi otomatis dengan gabungan teks "TRX" dan nomor urut dari class variable
        self._no_pembayaran = f"TRX{MetodePembayaran._no_transaksi}"
        MetodePembayaran._no_transaksi += (1)  # menambahkan nomor urut transaksi sebanyak 1 untuk transaksi berikutnya

        self._status_pembayaran = ("Lunas")  # memperbarui nilai atribut status_pembayaran menjadi "Lunas"

    # getter alternatif untuk memeriksa dan mengembalikan status pembayaran saat ini
    def cek_status(self) -> str:
        return self._status_pembayaran  # mengembalikan string status_pembayaran

    # untuk menampilkan seluruh informasi detail pembayaran ke layar
    def tampil_pembayaran(self):
        print(f"Jenis Pembayaran  : {self._jenis_pembayaran}")  # mencetak jenis pembayaran ke layar
        print(f"Nomor Transaksi   : {self._no_pembayaran}")  # mencetak nomor transaksi ke layar
        print(f"Status Pembayaran : {self._status_pembayaran}")  # mencetak status pembayaran ke layar