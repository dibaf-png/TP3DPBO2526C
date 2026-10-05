# Mengimpor class MetodePemesanan dari file MetodePemesanan.py.
from MetodePemesanan import MetodePemesanan

# Mengimpor class ItemPesanan dari file ItemPesanan.py.
from ItemPesanan import ItemPesanan

# Mengimpor class MetodePembayaran dari file MetodePembayaran.py.
from MetodePembayaran import MetodePembayaran

# Mengimpor class DriveThru dari file DriveThru.py.
from DriveThru import DriveThru

# Mengimpor class SelfService dari file SelfService.py.
from SelfService import SelfService

# Mengimpor class TableService dari file TableService.py.
from TableService import TableService

# Mengimpor class OnlineDelivery dari file OnlineDelivery.py.
from OnlineDelivery import OnlineDelivery

# Mengimpor class Pesanan dari file Pesanan.py.
from Pesanan import Pesanan


# Membuat list of dictionary untuk menyimpan data nama dan harga setiap menu.
daftarMenu = [
    {"nama": "Burger Keju", "harga": 35000},     # Menu indeks 0
    {"nama": "Kentang Goreng", "harga": 18000},  # Menu indeks 1
    {"nama": "Ice Coffe", "harga": 18500}        # Menu indeks 2
]


# Membuat fungsi untuk menerima input teks dari pengguna.
def inputTeks(pesan):

    # Melakukan perulangan sampai pengguna memberikan input yang valid.
    while True:

        # Menampilkan pesan dan membaca input dari pengguna.
        hasil = input(pesan)

        # Mengecek apakah input tidak kosong (menghapus spasi di awal/akhir).
        if hasil.strip() != "":

            # Mengembalikan hasil input jika tidak kosong.
            return hasil

        # Menampilkan pesan kesalahan jika input kosong.
        print("Input tidak boleh kosong!")


# Membuat fungsi untuk menerima input angka dengan batas minimum dan maksimum.
def inputAngka(pesan, minimum, maksimum):

    # Melakukan perulangan sampai pengguna memberikan input yang valid.
    while True:

        # Menggunakan try untuk menangani input yang bukan angka.
        try:

            # Membaca input dari pengguna lalu mengubahnya menjadi integer.
            angka = int(input(pesan))

            # Mengecek apakah angka berada dalam rentang yang ditentukan.
            if angka >= minimum and angka <= maksimum:

                # Mengembalikan angka jika input valid.
                return angka

            # Menampilkan pesan jika angka berada di luar rentang.
            print("Input tidak valid!")

        # Menangkap error jika input bukan berupa angka.
        except ValueError:

            # Menampilkan pesan kesalahan kepada pengguna.
            print("Input tidak valid!")


# Membuat fungsi untuk menerima input angka dengan batas minimum.
def inputAngkaMinimal(pesan, minimum):

    # Melakukan perulangan sampai pengguna memberikan input yang valid.
    while True:

        # Menggunakan try untuk menangani input yang bukan angka.
        try:

            # Membaca input dari pengguna lalu mengubahnya menjadi integer.
            angka = int(input(pesan))

            # Mengecek apakah angka memenuhi batas minimum.
            if angka >= minimum:

                # Mengembalikan angka jika input valid.
                return angka

            # Menampilkan pesan jika angka kurang dari batas minimum.
            print("Input tidak valid!")

        # Menangkap error jika input bukan berupa angka.
        except ValueError:

            # Menampilkan pesan kesalahan kepada pengguna.
            print("Input tidak valid!")


# Membuat fungsi untuk menerima pilihan y atau n dari pengguna.
def inputYaTidak():

    # Melakukan perulangan sampai pengguna memberikan input yang valid.
    while True:

        # Membaca input pengguna, menghapus spasi, dan mengubahnya ke huruf kecil.
        pilihan = input().strip().lower()

        # Mengecek apakah pengguna memilih y.
        if pilihan == "y":

            # Mengembalikan karakter y.
            return "y"

        # Mengecek apakah pengguna memilih n.
        if pilihan == "n":

            # Mengembalikan karakter n.
            return "n"

        # Menampilkan pesan kesalahan jika input bukan y atau n.
        print("Masukkan hanya y atau n: ", end="")


# Membuat fungsi untuk menampilkan seluruh menu makanan.
def tampilMenu():

    # Menampilkan baris kosong sebagai pemisah.
    print()

    # Menampilkan header judul daftar menu.
    print("     <<<<<<<<<< DAFTAR MENU >>>>>>>>>>")

    # Melakukan perulangan berdasarkan jumlah item di daftarMenu.
    for i in range(len(daftarMenu)):

        # Mengambil data menu berdasarkan indeks i.
        menu = daftarMenu[i]

        # Menampilkan nomor urut, nama menu, dan harganya.
        print(f"{i + 1}. {menu['nama']} - Rp.{menu['harga']}")


# Membuat fungsi untuk menampilkan seluruh data pesanan yang tersimpan.
def tampilkanSemuaPesanan(daftarPesanan):

    # Mengecek apakah daftar pesanan masih kosong.
    if len(daftarPesanan) == 0:

        # Menampilkan baris kosong.
        print()

        # Menampilkan informasi bahwa belum ada data pesanan.
        print("Belum ada data pesanan.")

        # Menghentikan eksekusi fungsi.
        return

    # Melakukan perulangan untuk setiap objek pesanan dalam daftar.
    for i in range(len(daftarPesanan)):

        # Memanggil method tampilPesanan dari objek Pesanan.
        daftarPesanan[i].tampil_pesanan()

        # Menampilkan garis pemisah antar pesanan.
        print("-" * 40)


# Membuat fungsi utama untuk menjalankan alur program.
def main():

    # Membuat list kosong untuk menyimpan seluruh objek Pesanan.
    daftarPesanan = []

    # Membuat list kosong untuk menyimpan objek DriveThru.
    daftarDriveThru = []

    # Membuat list kosong untuk menyimpan objek SelfService.
    daftarSelfService = []

    # Membuat list kosong untuk menyimpan objek TableService.
    daftarTableService = []

    # Membuat list kosong untuk menyimpan objek OnlineDelivery.
    daftarOnlineDelivery = []

    # Melakukan perulangan utama untuk menampilkan menu aplikasi.
    while True:

        # Menampilkan opsi menu utama sistem.
        print("\n      <<<<<<<<<< SISTEM PEMESANAN MAKANAN >>>>>>>>>>")
        print("1. Tambah Data Pesanan")
        print("2. Tampilkan Data Pesanan")
        print("3. Keluar")

        # Meminta pengguna memilih menu utama (antara 1 sampai 3).
        pilihanMenu = inputAngka("Pilih menu : ", 1, 3)

        # Mengolah jika pengguna memilih opsi 1 (Tambah Data Pesanan).
        if pilihanMenu == 1:

            # Menginstansiasi objek Pesanan baru.
            pesananBaru = Pesanan()

            # Menampilkan header input data pelanggan.
            print("\n========== DATA PELANGGAN ==========")

            # Meminta input nama pelanggan.
            namaPelanggan = inputTeks("Nama Pelanggan : ")

            # Meminta input waktu pemesanan.
            waktuPemesanan = inputTeks("Waktu Pemesanan : ")

            # Menampilkan header pilihan metode pemesanan.
            print("\n========== METODE PEMESANAN ==========")
            print("1. Drive Thru")
            print("2. Self Service")
            print("3. Table Service")
            print("4. Online Delivery")

            # Meminta pengguna memilih metode pemesanan (1 sampai 4).
            pilihanMetode = inputAngka("Pilih metode pemesanan : ", 1, 4)

            # Inisialisasi variabel untuk menyimpan instance metode pemesanan.
            metodeTerpilih = None

            # Jika memilih Drive Thru (pilihan 1).
            if pilihanMetode == 1:
                print("\n========== DRIVE THRU ==========")

                # Meminta input nomor kendaraan.
                nomorKendaraan = inputTeks("Nomor Kendaraan : ")

                # Meminta input jenis kendaraan.
                jenisKendaraan = inputTeks("Jenis Kendaraan : ")

                # Membuat objek DriveThru.
                metodeTerpilih = DriveThru(namaPelanggan, waktuPemesanan, nomorKendaraan, jenisKendaraan)

                # Menambahkan objek ke list DriveThru.
                daftarDriveThru.append(metodeTerpilih)

            # Jika memilih Self Service (pilihan 2).
            elif pilihanMetode == 2:

                # Membuat objek SelfService.
                metodeTerpilih = SelfService(namaPelanggan, waktuPemesanan)

                # Menambahkan objek ke list SelfService.
                daftarSelfService.append(metodeTerpilih)

            # Jika memilih Table Service (pilihan 3).
            elif pilihanMetode == 3:
                print("\n========== TABLE SERVICE ==========")

                # Meminta input jumlah pelanggan (minimal 1).
                jumlahPelanggan = inputAngkaMinimal("Jumlah Pelanggan : ", 1)

                # Membuat objek TableService.
                metodeTerpilih = TableService(namaPelanggan, waktuPemesanan, jumlahPelanggan)

                # Menambahkan objek ke list TableService.
                daftarTableService.append(metodeTerpilih)

            # Jika memilih Online Delivery (pilihan 4).
            elif pilihanMetode == 4:
                print("\n========== ONLINE DELIVERY ==========")
                print("1. GoFood")
                print("2. ShopeeFood")
                print("3. GrabFood")

                # Meminta input pilihan platform online.
                pilihanPlatform = inputAngka("Pilih platform : ", 1, 3)

                # Map opsi angka ke nama platform.
                platformMap = {1: "GoFood", 2: "ShopeeFood", 3: "GrabFood"}

                # Mengambil string nama platform dari dictionary.
                platform = platformMap[pilihanPlatform]

                # Meminta input alamat pengantaran.
                alamat = inputTeks("Alamat Pengantaran : ")

                # Meminta input jarak pengantaran dalam km (minimal 1).
                jarak = inputAngkaMinimal("Jarak Pengantaran (km) : ", 1)

                # Membuat objek OnlineDelivery.
                metodeTerpilih = OnlineDelivery(namaPelanggan, waktuPemesanan, platform, alamat, jarak)

                # Menambahkan objek ke list OnlineDelivery.
                daftarOnlineDelivery.append(metodeTerpilih)

            # Mengatur cara pemesanan ke dalam objek pesanan baru.
            pesananBaru.set_cara_pemesanan(metodeTerpilih, pilihanMetode)

            # Menampilkan daftar menu makanan yang tersedia.
            tampilMenu()

            # Inisialisasi variabel loop untuk menambah item menu.
            tambahLagi = "y"

            # Perulangan untuk menambah menu selama pengguna memasukkan 'y'.
            while tambahLagi == "y":

                # Meminta input nomor menu yang dipilih.
                pilihanMakanan = inputAngka("Pilih menu : ", 1, len(daftarMenu))

                # Meminta input jumlah porsi yang dibeli.
                jumlah = inputAngkaMinimal("Masukkan jumlah : ", 1)

                # Mengambil data dictionary menu berdasarkan pilihan pengguna.
                menuTerpilih = daftarMenu[pilihanMakanan - 1]

                # Membuat objek ItemPesanan berdasarkan data menu.
                itemBaru = ItemPesanan(menuTerpilih["nama"], menuTerpilih["harga"], jumlah)

                # Menambahkan item pesanan ke objek Pesanan.
                pesananBaru.tambah_pesanan(itemBaru)

                # Menanyakan apakah ingin menambah menu lain.
                print("Tambah menu lagi? [y/n]: ", end="")

                # Membaca konfirmasi y/n dari pengguna.
                tambahLagi = inputYaTidak()

            # Inisialisasi biaya kirim awal 0.
            biayaKirim = 0

            # Jika metode pemesanan adalah Online Delivery, hitung biaya kirimnya.
            if pilihanMetode == 4 and isinstance(metodeTerpilih, OnlineDelivery):
                biayaKirim = metodeTerpilih.get_biaya_kirim()

            # Menghitung total biaya pesanan termasuk biaya kirim.
            pesananBaru.hitung_total(biayaKirim)

            # Menampilkan rincian pembayaran.
            print("\n========== RINCIAN PEMBAYARAN ==========")

            # Menghitung subtotal pesanan (tanpa ongkir).
            subtotal = pesananBaru.get_total_bayar() - biayaKirim

            # Menampilkan rincian harga subtotal, biaya kirim, dan total bayar.
            print(f"Subtotal Pesanan : Rp.{subtotal}")
            print(f"Biaya Kirim      : Rp.{biayaKirim}")
            print(f"Total Bayar      : Rp.{pesananBaru.get_total_bayar()}")

            # Menampilkan pilihan metode pembayaran.
            print("\n========== METODE PEMBAYARAN ==========")
            print("1. Cash")
            print("2. Debit")
            print("3. QRIS")
            print("4. E-Wallet")

            # Meminta pengguna memilih opsi pembayaran (1 sampai 4).
            pilihanPembayaran = inputAngka("Pilih metode pembayaran : ", 1, 4)

            # Map opsi angka ke jenis pembayaran.
            pembayaranMap = {1: "Cash", 2: "Debit", 3: "QRIS", 4: "E-Wallet"}

            # Mengambil string jenis pembayaran.
            jenisPembayaran = pembayaranMap[pilihanPembayaran]

            # Mengatur jenis pembayaran pada objek Pesanan.
            pesananBaru.set_jenis_pembayaran(jenisPembayaran)

            # Memproses dan mengonfirmasi pembayaran pesanan.
            pesananBaru.bayar_pesanan()

            # Menampilkan pesan bahwa transaksi berhasil ditambahkan.
            print("\nData berhasil ditambahkan!")

            # Menambahkan objek pesanan ke list utama daftarPesanan.
            daftarPesanan.append(pesananBaru)

        # Mengolah jika pengguna memilih opsi 2 (Tampilkan Data Pesanan).
        elif pilihanMenu == 2:

            # Memanggil fungsi untuk menampilkan seluruh pesanan yang tersimpan.
            tampilkanSemuaPesanan(daftarPesanan)

        # Mengolah jika pengguna memilih opsi 3 (Keluar).
        elif pilihanMenu == 3:

            # Menampilkan pesan penutup.
            print("\nProgram selesai. Terima kasih!")

            # Menghentikan loop utama program.
            break


# Mengecek apakah file dijalankan sebagai skrip utama.
if __name__ == "__main__":

    # Memanggil fungsi main untuk memulai program.
    main()