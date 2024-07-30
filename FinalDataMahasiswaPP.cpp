#include <iostream>
#include <string>

using namespace std;

// struktur data mahasiswa
struct Mahasiswa {
     string nama;
     string jurusan;
     string kelas;
     string npm;
     double ipk;
};

const int MAX_MAHASISWA = 100; // batas maksimum mahasiswa
Mahasiswa dataMahasiswa[MAX_MAHASISWA]; // array untuk menyimpan data mahasiswa
int jumlahMahasiswa = 0; // variabel untuk menyimpan jumlah mahasiswa yang sudah dimasukan
string npmCari; // variabel untuk menyimpan npm yang dicari

// deklarasi fungsi-fungsi
void tambahMahasiswa();
void tampilkanMahasiswa();
void cariMahasiswa();
void hapusMahasiswa();
double inputNilai(double);
double nilaiMean(double, double, double, double, double, double, double);

// fungsi utama
int main() {
     int pilihan;

     // loop utama program
     do {
          // tampilan menu utama
          cout << "|====================================|" << endl;
          cout << "|       Program Data Mahasiswa       |" << endl;
          cout << "|====================================|" << endl;
          cout << "|1. Tambah Mahasiswa                 |" << endl;
          cout << "|2. Hapus Mahasiswa                  |" << endl;
          cout << "|3. Tampilkan Mahasiswa              |" << endl;
          cout << "|4. Cari Mahasiswa                   |" << endl;
          cout << "|5. Keluar                           |" << endl;
          cout << "|====================================|" << endl;
          cout << "Pilih menu (1/2/3/4/5) : ";
          cin >> pilihan;

          // memilih aksi sesuai input pengguna
          switch (pilihan) {
               case 1:
                    tambahMahasiswa();
                    break;
               case 2:
                    hapusMahasiswa();
                    break;
               case 3:
                    tampilkanMahasiswa();
                    break;
               case 4:
                    cariMahasiswa();
                    break;
               case 5:
                    cout << "\nKeluar Dari Program.\n\n" << endl;
                    break;
               default:
                    cout << "\nPilihan Tidak Valid.\n\n" << endl;
          }

     } while (pilihan != 5); // program berjalan selama input pengguna bukan 5

     return 0;
}


// fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa() {
     // struktur lokal untuk menyimpan nilai mahasiswa
     struct Nilai {
          double Alpro;
          double Matdis;
          double Inggris;
          double Pti;
          double Kwn;
          double Kalkulus;
          double Fisdas;
     } nilaiMhs;

     // memastikan jumlah mahasiswa belom mencapai batas maksimum (100)
     if (jumlahMahasiswa < MAX_MAHASISWA) {
          Mahasiswa mhs;
          cout << endl;

          // menginput data mahasiswa
          cout << "Masukkan Nama Mahasiswa           : ";
          cin.ignore(); //Mengbaikan spasi agar yang diinput bukan hanya 1 kata
          getline(cin, mhs.nama); //untuk membaca satu baris termasuk spasi hingga baris baru

          cout << "Masukkan Jurusan Mahasiswa        : ";
          getline(cin, mhs.jurusan); //untuk membaca satu baris termasuk spasi hingga baris baru

          cout << "Masukkan Kelas Mahasiswa          : ";
          cin.ignore(); //Mengabaikan spasi agar yang diinput bukan hanya 1 kata
          getline(cin, mhs.kelas); //untuk membaca satu baris termasuk spasi hingga baris baru

          cout << "Masukkan NPM Mahasiswa            : ";
          getline(cin, mhs.npm);

          cout << "Masukkan Nilai Alpro Mahasiswa    : ";
          nilaiMhs.Alpro = inputNilai(nilaiMhs.Alpro);

          cout << "Masukkan Nilai Matdis Mahasiswa   : ";
          nilaiMhs.Matdis = inputNilai(nilaiMhs.Matdis);

          cout << "Masukkan Nilai Inggris Mahasiswa  : ";
          nilaiMhs.Inggris = inputNilai(nilaiMhs.Inggris);

          cout << "Masukkan Nilai PTI Mahasiswa      : ";
          nilaiMhs.Pti = inputNilai(nilaiMhs.Pti);

          cout << "Masukkan Nilai KWN Mahasiswa      : ";
          nilaiMhs.Kwn = inputNilai(nilaiMhs.Kwn);

          cout << "Masukkan Nilai Kalkulus Mahasiswa : ";
          nilaiMhs.Kalkulus = inputNilai(nilaiMhs.Kalkulus);

          cout << "Masukkan Nilai Fisdas Mahasiswa   : ";
          nilaiMhs.Fisdas = inputNilai(nilaiMhs.Fisdas);

          // menghitung rata-rata nilai dan menentukan IPK
          double rataNilai = nilaiMean(nilaiMhs.Alpro, nilaiMhs.Matdis, nilaiMhs.Inggris, nilaiMhs.Pti, nilaiMhs.Kwn, nilaiMhs.Kalkulus, nilaiMhs.Fisdas);

          if (rataNilai >= 80) {
               mhs.ipk = 4.0;
          } else if (rataNilai >= 75) {
               mhs.ipk = 3.5;
          } else if (rataNilai >= 70) {
               mhs.ipk = 3.0;
          } else if (rataNilai >= 65) {
               mhs.ipk = 2.5;
          } else if (rataNilai >= 60) {
               mhs.ipk = 2.0;
               cout << "Mahasiswa Disarankan Untuk Mengulang !\n\n";
          } else {
               mhs.ipk = 1.5;
               cout << "Mahasiswa Disarankan Untuk Mengulang !\n\n";
          }

          // menyimpan data mahasiswa ke dalam array
          dataMahasiswa[jumlahMahasiswa] = mhs;
          jumlahMahasiswa++;

          cout << "Data Mahasiswa Berhasil Ditambahkan." << endl;
          cout << endl;
     } else {
          cout << "Kuota Mahasiswa Telah Penuh." << endl;
          cout << endl;
     }
}

// fungsi untuk menghapus data mahasiswa berdasarkan NPM
void hapusMahasiswa() {
     // memeriksa apakah ada daftar mahasiswa
     if (jumlahMahasiswa == 0) {
          cout << "\nData Mahasiswa Masih Kosong.\n\n" << endl;
          return;
     }

     cout << "\nMasukkan NPM Mahasiswa yang Akan Dihapus : ";
     cin >> npmCari;

     int i = 0;
     // melakukan pencarian berdasarkan NPM
     while(i < jumlahMahasiswa) {
          if (dataMahasiswa[i].npm == npmCari) {
               // menggeser data untuk menutup posisi yang dihapus
               for (int j = i; j < jumlahMahasiswa - 1; j++) {
                    dataMahasiswa[j] = dataMahasiswa[j + 1];
               }
               jumlahMahasiswa--;

               cout << "Mahasiswa dengan NPM " << npmCari << " berhasil dihapus.\n\n";
               return;
          }
          i++;
     }

     // tampilan jika NPM tidak ditemukan
     cout << "Mahasiswa dengan NPM " << npmCari << " tidak ditemukan.\n\n" << endl;
}

// fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa() {
     // memeriksa apakah ada daftar mahasiswa
     if (jumlahMahasiswa == 0) {
          cout << "\nData Mahasiswa Masih Kosong.\n\n" << endl;
     } else {
          cout << "\nDaftar Mahasiswa :" << endl;
          for (int i = 0; i < jumlahMahasiswa; i++) {
               cout << "Nama      : " << dataMahasiswa[i].nama << endl;
               cout << "Jurusan   : " << dataMahasiswa[i].jurusan << endl;
               cout << "Kelas     : " << dataMahasiswa[i].kelas << endl;
               cout << "NPM       : " << dataMahasiswa[i].npm << endl;
               cout << "IPK       : " << dataMahasiswa[i].ipk << endl;
               cout << endl;
          }
     }
}


// fungsi untuk mencari mahasiswa berdasarkan NPM
void cariMahasiswa() {
     cout << endl;

     cout << "Masukkan NPM Mahasiswa yang Dicari : ";
     cin >> npmCari;

     int i = 0;
     // melakukan pencarian berdasarkan NPM
     while(i < jumlahMahasiswa){
          if (dataMahasiswa[i].npm == npmCari) {
               cout << "Mahasiswa Ditemukan :" << endl;
               cout << "Nama      : " << dataMahasiswa[i].nama << endl;
               cout << "Jurusan   : " << dataMahasiswa[i].jurusan << endl;
               cout << "Kelas     : " << dataMahasiswa[i].kelas << endl;
               cout << "IPK       : " << dataMahasiswa[i].ipk << endl;
               cout << endl;
               return;
          }
          i++;
     }
     
     // tampilan jika NPM tidak didak ditemukan
     cout << "Mahasiswa Dengan NPM " << npmCari << " Tidak Ditemukan.\n\n" << endl;
}


double inputNilai(double nilai){
     do{
          cin >> nilai;
          if (nilai < 0 || nilai > 100){
               cout << "Nilai Yang Anda Masukkan Tidak Valid. Silakan Coba Lagi.\n";
               cout << "Masukkan Nilai Mahasiswa          : ";
          }
     } while (nilai < 0 || nilai > 100);
     return nilai;
};

// fungsi untuk menghitung rata-rata nilai
double nilaiMean(double skorAlpro, double skorMatdis, double skorInggris, double skorPti, double skorKwn, double skorKalkulus, double skorFisdas){
    return (skorAlpro + skorMatdis + skorInggris + skorPti + skorKwn + skorKalkulus + skorFisdas) / 7.0;
};
