from typing import List, Optional
from ItemPesanan import ItemPesanan
from MetodePembayaran import MetodePembayaran
from MetodePemesanan import MetodePemesanan

class Pesanan:  # membuat class Pesanan untuk mengelola seluruh data transaksi, item, pembayaran, dan metode pemesanan
    # Variabel class (static) untuk menyimpan nomor urut pesanan yang nilainya bertahan selama program berjalan
    _no_pesanan = 1

    # Constructor (__init__) untuk menginisialisasi nilai awal saat objek Pesanan pertama kali dibuat
    def __init__(self):
        # membuat ID unik dengan gabungan string "PSN" dan angka nomor urut
        self._id_pesanan = f"PSN{Pesanan._no_pesanan}"
        # menambahkan nilai _no_pesanan sebanyak 1 untuk pesanan berikutnya
        Pesanan._no_pesanan += 1

        self._total_bayar = 0  # menginisialisasi total_bayar dengan angka 0
        self._status_pesanan = ("Dibuat")  # mengatur status awal pesanan menjadi "Dibuat"
        self._list_pesanan: List[ItemPesanan] = ([])  # variabel list_pesanan berupa list berisi objek-objek ItemPesanan
        self._pembayaran = (MetodePembayaran())  # variabel atribut pembayaran berupa objek dari kelas MetodePembayaran
        self._cara_pemesanan: Optional[MetodePemesanan] = (None)  # mengatur cara_pemesanan ke None (belum menunjuk objek metode pemesanan apa pun)
        self._jenis_metode = 0  # mengatur penanda jenis_metode awal ke angka 0

    # getter untuk mengambil dan mengembalikan nilai id_pesanan
    def get_id_pesanan(self) -> str:
        return self._id_pesanan  # mengembalikan string id_pesanan

    # getter untuk mengambil dan mengembalikan nilai total_bayar
    def get_total_bayar(self) -> int:
        return self._total_bayar  # mengembalikan nilai total_bayar

    # getter untuk mengambil dan mengembalikan nilai status_pesanan
    def get_status_pesanan(self) -> str:
        return self._status_pesanan  # mengembalikan string status_pesanan

    # getter untuk mengambil dan mengembalikan angka kode jenis_metode
    def get_jenis_metode(self) -> int:
        return self._jenis_metode  # mengembalikan angka jenis_metode

    # getter untuk mengambil dan mengembalikan objek cara_pemesanan
    def get_cara_pemesanan(self) -> Optional[MetodePemesanan]:
        return (self._cara_pemesanan)  # mengembalikan referensi objek cara_pemesanan

    # getter untuk mengambil dan mengembalikan objek pembayaran
    def get_pembayaran(self) -> MetodePembayaran:
        return self._pembayaran  # mengembalikan objek pembayaran

    # setter untuk mengatur metode pemesanan dan menandai jenis metodenya
    def set_cara_pemesanan(self, cara_pemesanan: MetodePemesanan, jenis_metode: int):
        self._cara_pemesanan = (cara_pemesanan)  # mengarahkan atribut cara_pemesanan ke objek metode pemesanan yang dikirim
        self._jenis_metode = (jenis_metode)  # mengisi angka penanda jenis_metode sesuai input parameter

    # untuk menambahkan objek ItemPesanan baru ke dalam list list_pesanan
    def tambah_pesanan(self, item: ItemPesanan):
        self._list_pesanan.append(item)  # memasukkan objek item ke urutan terakhir pada list list_pesanan

    # untuk menghitung total biaya keseluruhan pesanan (subtotal item + biaya kirim)
    def hitung_total(self, biaya_kirim: int = 0):
        self._total_bayar = (biaya_kirim) # mengeset total_bayar awal dengan nilai biaya kirim (default: 0)

        # Perulangan untuk menjumlahkan subtotal dari seluruh item yang ada di list list_pesanan
        for item in self._list_pesanan:
            self._total_bayar += (item.hitung_subtotal())  # menambahkan subtotal item ke total_bayar

    # untuk menentukan jenis metode pembayaran pada objek pembayaran
    def set_jenis_pembayaran(self, jenis: str):
        self._pembayaran.set_jenis(jenis)  # memanggil set_jenis() milik objek pembayaran

    # untuk memproses pembayaran dan mengubah status pesanan menjadi Dibayar
    def bayar_pesanan(self):
        self._pembayaran.proses_pembayaran()  # memanggil proses_pembayaran() milik objek pembayaran untuk mendapatkan nomor transaksi
        self._status_pesanan = "Dibayar"  # mengubah status pesanan menjadi "Dibayar"

    # untuk menampilkan seluruh detail rincian data pesanan ke layar
    def tampil_pesanan(self):
        print()  # mencetak baris baru untuk kerapian tampilan
        print("        <<<<<<<<<< DATA PESANAN >>>>>>>>>>")  # mencetak judul header
        print(f"ID Pesanan        : {self._id_pesanan}")  # mencetak ID pesanan
        print(f"Status Pesanan    : {self._status_pesanan}")  # mencetak status pesanan ke layar

        print()  # mencetak baris baru

        # memeriksa apakah cara_pemesanan tidak None (menunjuk ke salah satu objek metode pemesanan)
        if self._cara_pemesanan is not None:
            self._cara_pemesanan.tampil_metode()  # memanggil method tampil_metode() milik kelas induk untuk mencetak ID, Nama, dan Waktu

            # pengecekan jika jenis_metode bernilai 1 (Drive Thru)
            if self._jenis_metode == 1:
                # di Python tidak memerlukan static_cast, objek cara_pemesanan langsung diakses atributnya
                data_drive_thru = self._cara_pemesanan

                # mencetak rincian khusus layanan Drive Thru
                print("Metode Pemesanan : Drive Thru")
                print(f"Nomor Kendaraan  : {data_drive_thru.get_nomor_kendaraan()}")  # mencetak plat nomor kendaraan
                print(f"Jenis Kendaraan  : {data_drive_thru.get_jenis_kendaraan()}")  # mencetak jenis kendaraan
                print(f"Nomor Loket      : {data_drive_thru.get_nomor_loket()}")  # mencetak nomor loket

            # pengecekan jika jenis_metode bernilai 2 (Self Service)
            elif self._jenis_metode == 2:
                data_self_service = self._cara_pemesanan

                # mencetak rincian khusus layanan Self Service
                print("Metode Pemesanan : Self Service")
                print(f"Nomor Kiosk      : {data_self_service.get_nomor_kiosk()}")  # mencetak nomor kiosk
                print(f"Nomor Antrian    : {data_self_service.get_nomor_antrian()}")  # mencetak nomor antrean

            # pengecekan jika jenis_metode bernilai 3 (Table Service)
            elif self._jenis_metode == 3:
                data_table_service = self._cara_pemesanan

                # mencetak rincian khusus layanan Table Service
                print("Metode Pemesanan : Table Service")
                print(f"Nomor Meja       : {data_table_service.get_nomor_meja()}")  # mencetak nomor meja
                print(f"Jumlah Pelanggan : {data_table_service.get_jumlah_pelanggan()}")  # mencetak jumlah pelanggan
                print(f"Nama Pelayan     : {data_table_service.get_nama_pelayan()}")  # mencetak nama pelayan

            # pengecekan jika jenis_metode bernilai 4 (Online Delivery)
            elif self._jenis_metode == 4:
                data_online_delivery = self._cara_pemesanan

                # mencetak rincian khusus layanan Online Delivery
                print("Metode Pemesanan : Online Delivery")
                print(f"Platform         : {data_online_delivery.get_nama_platform()}")  # mencetak nama platform
                print(f"Nama Kurir       : {data_online_delivery.get_nama_kurir()}")  # mencetak nama kurir
                print(f"Alamat           : {data_online_delivery.get_alamat_pesanan()}")  # mencetak alamat pengiriman
                print(f"Jarak            : {data_online_delivery.get_jarak_pengantaran()} km")  # mencetak jarak
                print(f"Biaya Kirim      : Rp.{data_online_delivery.get_biaya_kirim()}")  # mencetak biaya kirim

        print()  # mencetak baris baru
        print("Daftar Pesanan:")  # mencetak header daftar item pesanan

        # Perulangan untuk mencetak seluruh item pesanan dari list list_pesanan secara ringkas 1 baris
        for i, item in enumerate(self._list_pesanan):
            print(
                f"{i + 1}. {item.get_nama_produk()} (x{item.get_jumlah()}) | @ Rp.{item.get_harga()} = Rp.{item.hitung_subtotal()}"
            )  # mencetak rincian item dalam 1 baris

        # memanggil method untuk menampilkan detail nomor transaksi dan status pembayaran
        self._pembayaran.tampil_pembayaran()

        # menginisialisasi variabel lokal subtotal dengan nilai 0 untuk menghitung murni harga makanan/minuman
        subtotal = 0

        # perulangan untuk menghitung akumulasi total subtotal dari semua item pesanan
        for item in self._list_pesanan:
            subtotal += (item.hitung_subtotal())  # mengakumulasikan subtotal item

        print()  # mencetak baris baru
        print(f"Subtotal Pesanan : Rp.{subtotal}")  # mencetak total harga makanan/minuman tanpa ongkir

        biaya_kirim = (0) # Deklarasi variabel lokal biaya_kirim dengan nilai awal 0

        # Memeriksa jika jenis_metode adalah Online Delivery (4) untuk mengambil biaya kirim
        if self._jenis_metode == 4 and self._cara_pemesanan is not None:
            data_online_delivery = self._cara_pemesanan
            biaya_kirim = (data_online_delivery.get_biaya_kirim())  # Mengambil nilai biaya kirim dari objek OnlineDelivery

        print(f"Biaya Kirim      : Rp.{biaya_kirim}")  # mencetak biaya kirim ke layar
        print(f"Total Bayar      : Rp.{self._total_bayar}")  # mencetak total pembayaran akhir ke layar
        print("==================================================")  # mencetak garis penutup