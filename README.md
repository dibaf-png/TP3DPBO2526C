# JANJI
Saya Farah Diba Nur Malinda dengan NIM 2502083 mengerjakan Tugas Praktikum 2 dalam mata kuliah Desain dan Pemrograman 
Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

# DIAGRAM
<img width="1163" height="1226" alt="TP3 drawio" src="https://github.com/user-attachments/assets/54f1ffe8-725f-440f-a1ee-843766483c62" />

# ATRIBUT DAN METHOD
Pada Program ini terdapat 8 class yang terdiri dari beberapa atribut dan method, yaitu:
1. Pesanan
   - Atribut:
     - idPesanan → menyimpan ID pesanan.
     - totalBayar → menyimpan total pembayaran.
     - statusPesanan → menyimpan status pesanan.
     - listPesanan → menyimpan daftar makanan yang dipesan.
     - pembayaran → menyimpan metode pembayaran.
     - caraPemesanan → menyimpan metode pemesanan.
     - jenisMetode → mengetahui jenis metode pemesanan yang digunakan.
  - Method:
     - hitungTotal() → menghitung total harga pesanan.
     - ubahStatusPesanan() → mengubah status pesanan.
     - tambahPesanan() → menambahkan makanan ke pesanan.
     - setCaraPemesanan() → menentukan metode pemesanan.
     - setJenisPembayaran() → menentukan metode pembayaran.
     - bayarPesanan() → memproses pembayaran.
     - tampilPesanan() → menampilkan seluruh data pesanan.
   
3. ItemPesanan
   - Atribut:
     - namaProduk → nama makanan.
     - hargaProduk → harga makanan.
     - jumlahProduk → jumlah makanan yang dipesan.
  - Method:
    - hitungSubtotal() → menghitung harga × jumlah.
    - ubahJumlahProduk() → mengubah jumlah makanan.
    - tampilDaftar() → menampilkan detail makanan.
    - getNamaProduk() → mengambil nama produk.
    - getHargaProduk() → mengambil harga produk.
    - getJumlahProduk() → mengambil jumlah produk.
    - setNamaProduk() → mengubah nama produk.
    - setJumlahProduk() → mengubah jumlah produk.
    
4. MetodePembayaran
  - Atribut:
       - jenisPembayaran → menyimpan jenis pembayaran.
       - noPembayaran → menyimpan nomor transaksi.
       - statusPembayaran → menyimpan status pembayaran.
  - Method:
       - setJenis() → menentukan jenis pembayaran.
       - prosesPembayaran() → memproses pembayaran.
       - cekStatus() → mengecek status pembayaran.
       - tampilPembayaran() → menampilkan data pembayaran.
       - getJenis() → mengambil jenis pembayaran.
       - getNomor() → mengambil nomor transaksi.
       - getStatus() → mengambil status pembayaran.
   
4. MetodePemesanan
   - Atribut:
        - idMetode → ID metode pemesanan yang dibuat otomatis.
        - namaPelanggan → nama pelanggan.
        - waktuPemesanan → waktu pemesanan.
   - Method:
        - setNamaPelanggan() → mengubah nama pelanggan.
        - setWaktuPemesanan() → mengubah waktu pemesanan.
        - getIdMetode() → mengambil ID metode.
        - getNamaPelanggan() → mengambil nama pelanggan.
        - getWaktuPemesanan() → mengambil waktu pemesanan.
        - tampilMetode() → menampilkan data dasar metode pemesanan.
   
6. DriveThru
   - Atribut:
        - nomorKendaraan → nomor kendaraan pelanggan.
        - jenisKendaraan → jenis kendaraan.
        - nomorLoket → nomor loket yang ditentukan sistem.
   - Method:
        - setNomorKendaraan() → mengubah nomor kendaraan.
        - setJenisKendaraan() → mengubah jenis kendaraan.
        - getNomorKendaraan() → mengambil nomor kendaraan.
        - getJenisKendaraan() → mengambil jenis kendaraan.
        - getNomorLoket() → mengambil nomor loket.
        - cekLoket() → menentukan nomor loket.
        - tampilDriveThru() → menampilkan data Drive Thru.

6. SelfService
   - Atribut:
        - nomorKiosk → nomor kiosk yang digunakan.
        - nomorAntrian → nomor antrean pelanggan.
  - Method:
       - getNomorKiosk() → mengambil nomor kiosk.
       - getNomorAntrian() → mengambil nomor antrean.
       - pilihKiosk() → menentukan kiosk.
       - ambilNomorAntrian() → membuat nomor antrean.
       - tampilSelfService() → menampilkan data Self Service.
   
7. TableService
   - Atribut:
        - nomorMeja → nomor meja pelanggan.
        - jumlahPelanggan → jumlah pelanggan dalam satu pesanan.
        - namaPelayan → nama pelayan yang ditentukan sistem.
   - Method:
        - setJumlahPelanggan() → mengubah jumlah pelanggan.
        - getNomorMeja() → mengambil nomor meja.
        - getJumlahPelanggan() → mengambil jumlah pelanggan.
        - getNamaPelayan() → mengambil nama pelayan.
        - pilihMeja() → menentukan nomor meja.
        - pilihPelayan() → menentukan nama pelayan.
        - tampilTableService() → menampilkan data Table Service.
   
8. OnlineDelivery
    - Atribut:
         - namaPlatform → platform pemesanan.
         - namaKurir → nama kurir yang ditentukan sistem.
         - alamatPesanan → alamat pengantaran.
         - jarakPengantaran → jarak pengantaran.
         - biayaKirim → biaya pengiriman.
   - Method:
        - setNamaPlatform() → menentukan platform.
        - setAlamat() → mengubah alamat pengantaran.
        - setJarakPengantaran() → memasukkan jarak pengantaran.
        - getNamaPlatform() → mengambil nama platform.
        - getNamaKurir() → mengambil nama kurir.
        - getAlamatPesanan() → mengambil alamat.
        - getJarakPengantaran() → mengambil jarak.
        - getBiayaKirim() → mengambil biaya kirim.
        - pilihKurir() → menentukan kurir.
        - hitungBiayaKirim() → menghitung biaya pengiriman berdasarkan jarak.
        - tampilDelivery() → menampilkan data Online Delivery.

# ALUR PROGRAM
1. Program dijalankan.
2. Program menampilkan menu utama:
   - Tambah Data Pesanan
   - Tampilkan Data Pesanan
   - Keluar
3. Jika memilih Tambah Data Pesanan:
   - Input nama pelanggan.
   - Input waktu pemesanan.
   - Sistem membuat ID metode pemesanan secara otomatis.
   - Pilih metode pemesanan:
       - Drive Thru
       - Self Service
       - Table Service
       - Online Delivery
4. Jika memilih Drive Thru:
   - Input nomor kendaraan.
   - Input jenis kendaraan.
   - Sistem menentukan nomor loket.
5. Jika memilih Self Service:
   - Sistem menentukan nomor kiosk.
   - Sistem memberikan nomor antrean.
6. Jika memilih Table Service:
   - Input jumlah pelanggan.
   - Sistem menentukan nomor meja.
   - Sistem menentukan nama pelayan.
7. Jika memilih Online Delivery:
    - Input alamat pengantaran.
    - Pilih platform:
        - GoFood
        - ShopeeFood
        - GrabFood
    - Input jarak pengantaran.
    - Sistem menghitung biaya pengiriman.
    - Sistem menentukan nama kurir.
8. Sistem menampilkan daftar menu makanan.
9. Pengguna memilih makanan yang ingin dipesan.
10. Pengguna memasukkan jumlah makanan.
11. Sistem membuat objek ItemPesanan dan memasukkannya ke dalam Pesanan.
12. Program bertanya:
    - Tambah menu lagi? [y/n]
    - Jika y, pengguna kembali memilih menu.
    - Jika n, lanjut ke pembayaran.
13. Sistem menghitung subtotal setiap makanan.
14. Sistem menghitung total pembayaran, termasuk biaya pengiriman jika menggunakan Online Delivery.
15. Pengguna memilih metode pembayaran:
    - Cash
    - Debit
    - QRIS
    - E-Wallet
16. Sistem membuat nomor transaksi pembayaran secara otomatis.
17. Sistem memproses pembayaran dan menentukan status pembayaran.
18. Sistem membuat ID pesanan secara otomatis.
19. Data pesanan disimpan ke dalam vector<Pesanan> sebagai array of object.
20. Program kembali ke menu utama.
21. Jika memilih Tampilkan Data Pesanan:
    - Sistem mengecek apakah ada data pesanan.
    - Jika belum ada, tampilkan "Belum ada data pesanan."
    - Jika ada, tampilkan seluruh data pesanan secara lengkap:
        - ID pesanan
        - Data pelanggan
        - Metode pemesanan
        - Detail makanan
        - Pembayaran
        - Subtotal
        - Biaya pengiriman
        - Total pembayaran
        - Status pesanan
22. Setelah data ditampilkan, program kembali ke menu utama.
23. Jika memilih Keluar:
Program berhenti.

# RELASI DAN HUBUNGAN ANTAR CLASS
- Composition
  - Relasi Pesanan dan ItemPesanan, karena ItemPesanan merupakan bagian dari Pesanan dan disimpan di dalam vector<ItemPesanan> milik Pesanan.
  - Dampaknya: ItemPesanan memiliki ketergantungan kuat terhadap Pesanan. Jika objek Pesanan dihapus, maka ItemPesanan yang menjadi bagian dari Pesanan tersebut juga ikut terhapus.

- Association
  - Relasi Pesanan dan MetodePembayaran, karena Pesanan menggunakan MetodePembayaran untuk melakukan pembayaran.
  - Dampaknya: kedua kelas tidak memiliki ketergantungan siklus hidup yang kuat. Pesanan dapat menggunakan MetodePembayaran tanpa membuat MetodePembayaran menjadi bagian yang wajib dimiliki oleh Pesanan.

  - Relasi Pesanan dan MetodePemesanan, karena Pesanan menggunakan salah satu metode pemesanan seperti DriveThru, SelfService, TableService, atau OnlineDelivery.
  - Dampaknya: Pesanan hanya berhubungan atau menggunakan objek MetodePemesanan. Objek metode pemesanan dapat tetap berdiri sendiri dan tidak otomatis terhapus hanya karena Pesanan dihapus.

- Hierarchical Inheritance
  - Relasi MetodePemesanan dengan DriveThru, SelfService, TableService, dan OnlineDelivery, karena keempat kelas tersebut merupakan turunan dari MetodePemesanan dan memiliki karakteristik dasar yang sama sebagai metode pemesanan.
  - Dampaknya: setiap kelas anak otomatis mendapatkan atribut dan method yang dimiliki MetodePemesanan, sehingga tidak perlu menulis ulang bagian yang sama. Namun, masing-masing kelas anak tetap dapat memiliki atribut dan method khusus sesuai jenis pemesanannya.

# DOKUMENTASI
- cpp
  Tampilan ketika data masih kosong:
  
  <img width="467" height="159" alt="tampil data_kosong" src="https://github.com/user-attachments/assets/1e1a2885-9660-4a5f-926a-10c0b916bbbd" />

  Tambah data:
  
  <img width="411" height="611" alt="tambah_data" src="https://github.com/user-attachments/assets/a4adfed1-72f3-4d85-bd49-58a85e3faf52" />

  Tampil data:
  
  <img width="399" height="415" alt="tampil data" src="https://github.com/user-attachments/assets/2b6cf297-0cc5-4c0a-829a-c414c3092e62" />

- python
  Tampilan ketika data masin kosong:
  
  <img width="340" height="101" alt="data_kosong" src="https://github.com/user-attachments/assets/73b96ba5-0fb3-4445-95ba-cb2af37aea3e" />
  

  Tambah data:
  
  <img width="339" height="532" alt="tambah_data" src="https://github.com/user-attachments/assets/499edd0c-32aa-487b-83de-bf93a16e5dfa" />

  Tampil data:
  
  <img width="332" height="299" alt="tampilkan_data" src="https://github.com/user-attachments/assets/c57db768-14df-4456-ac0c-1abf05c4ca3d" />

