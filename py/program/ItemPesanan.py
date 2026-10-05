class ItemPesanan:  # membuat class bernama ItemPesanan untuk mengelola data tiap produk yang dipesan
    # Constructor (__init__) untuk menginisialisasi objek ItemPesanan saat dibuat
    def __init__(self, nama_produk: str, harga_produk: int, jumlah_produk: int):
        self._nama_produk = nama_produk  # mengisi atribut _nama_produk dengan nilai dari parameter nama_produk
        self._harga_produk = harga_produk  # mengisi atribut _harga_produk dengan nilai dari parameter harga_produk
        self._jumlah_produk = jumlah_produk  # mengisi atribut _jumlah_produk dengan nilai dari parameter jumlah_produk

    # getter untuk mengambil dan mengembalikan nilai namaProduk
    def get_nama_produk(self) -> str:
        return self._nama_produk  # mengembalikan nilai dari variabel _nama_produk

    # getter untuk mengambil dan mengembalikan nilai hargaProduk
    def get_harga(self) -> int:
        return self._harga_produk  # mengembalikan nilai dari variabel _harga_produk

    # getter untuk mengambil dan mengembalikan nilai jumlahProduk
    def get_jumlah(self) -> int:
        return self._jumlah_produk  # mengembalikan nilai dari variabel _jumlah_produk

    # setter untuk memperbarui atau mengubah nilai namaProduk
    def set_nama_produk(self, nama_produk: str):
        self._nama_produk = nama_produk  # memperbarui nilai atribut _nama_produk dengan data baru dari parameter

    # setter untuk memperbarui atau mengubah nilai jumlahProduk
    def set_jumlah(self, jumlah_produk: int):
        self._jumlah_produk = jumlah_produk  # memperbarui nilai atribut _jumlah_produk dengan data baru dari parameter

    # untuk mengubah kuantitas/jumlah produk (fungsi operasional)
    def ubah_jumlah_produk(self, jumlah_produk: int):
        self._jumlah_produk = jumlah_produk  # memperbarui jumlah produk yang dipesan

    # untuk menghitung total harga item (harga * jumlah)
    def hitung_subtotal(self) -> int:
        return self._harga_produk * self._jumlah_produk  # mengembalikan hasil perkalian antara _harga_produk dan _jumlah_produk

    # untuk menampilkan seluruh detail rincian produk ke layar
    def tampil_item(self):
        print(f"Nama Produk   : {self._nama_produk}")  # Mencetak nama produk ke layar
        print(f"Harga Produk  : {self._harga_produk}")  # Mencetak harga satuan produk ke layar
        print(f"Jumlah Produk : {self._jumlah_produk}")  # Mencetak jumlah item yang dipesan ke layar
        print(f"Subtotal      : {self.hitung_subtotal()}")  # Mencetak subtotal harga produk