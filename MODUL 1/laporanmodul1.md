# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (1)</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Materi ini memberikan panduan komprehensif mengenai penggunaan IDE Code::Blocks untuk pengembangan program C++. Anda akan mempelajari alur kerja dasar, mulai dari proses instalasi, manajemen proyek, hingga teknik debugging. Fokus utama bagian awal adalah membekali Anda dengan kemampuan menangani masalah teknis, seperti penggunaan fitur "Clean project" dan analisis pesan kesalahan (error messages).
Bagian selanjutnya akan membahas fundamental pemrograman C++. Topik mencakup struktur kode, klasifikasi tipe data (seperti int dan float), serta penggunaan variabel dan operator. Selain itu, Anda akan mendalami logika kontrol alur, yang meliputi pernyataan kondisional (if-else, switch) untuk pengambilan keputusan dan mekanisme perulangan (for, while, do-while) untuk efisiensi eksekusi perintah.
### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nPenjumlahan : " << a + b << endl;
    cout << "Pengurangan : " << a - b << endl;
    cout << "Perkalian   : " << a * b << endl;
    cout << "Pembagian   : " << a / b << endl;

    return 0;
}

```
Penjelasan singkat 1
Program ini dimulai dengan menyertakan pustaka iostream untuk kebutuhan input-output dan menggunakan namespace std agar penulisan perintah menjadi lebih ringkas. Di dalam fungsi utama, program mendeklarasikan dua variabel bernama a dan b dengan tipe data float agar dapat mengolah bilangan bulat maupun desimal.
Selanjutnya, program berinteraksi dengan pengguna melalui perintah cout untuk meminta input, yang kemudian ditangkap oleh perintah cin dan disimpan ke dalam kedua variabel tersebut. Di bagian akhir, program melakukan proses kalkulasi secara langsung dan menampilkan hasilnya ke layar, mencakup empat operasi aritmatika dasar yaitu penjumlahan, pengurangan, perkalian, dan pembagian.


### 2. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100 ) {
        cout << "Angka di luar jangkauan" << endl;

        return 0;
    }

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam",  "tujuh", "delapan", "sembilan"};
    string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    if (angka == 0) {
        cout << "Nol" << endl;
    } else if (angka == 100) {
        cout << "Seratus" << endl;
    } else if (angka >= 10 && angka < 20) {
        cout << belasan[angka - 10] << endl;
    } else {
        int puluh = angka / 10;
        int satu = angka % 10;

        if (puluh > 0) cout << puluhan[puluh];
        if (puluh > 0 && satu > 0) cout << " ";
        if (satu >  0) cout << satuan[satu];
        cout << endl;
    }
    return 0;
}

```
penjelasan singkat 2
Program ini berfungsi untuk mengubah input angka 0 hingga 100 menjadi teks penyebutannya dengan memanfaatkan "kamus" kata yang disimpan dalam array. Awalnya, program melakukan validasi agar angka yang dimasukkan tidak keluar dari jangkauan, kemudian menggunakan logika if-else untuk menentukan kategori angka tersebut. Jika angka bukan 0, 100, atau belasan, program akan memecah angka tersebut menggunakan operasi matematika (pembagian dan sisa bagi) untuk mendapatkan nilai puluhan dan satuannya, lalu merangkai kata-kata tersebut menjadi satu kalimat yang utuh.

### 3. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}



```
penjelasan singkat  3
Program ini digunakan untuk mencetak sebuah pola angka dan simbol bintang (*) yang membentuk segitiga terbalik simetris. Secara teknis, program menggunakan perulangan bersarang (nested loop) di mana baris demi baris dicetak mulai dari angka terbesar hingga terkecil. Di setiap barisnya, terdapat tiga bagian utama: pertama adalah spasi untuk menggeser posisi, kedua adalah urutan angka yang menurun, lalu simbol bintang sebagai pusat, dan terakhir adalah urutan angka yang menaik kembali. Setelah pola segitiga selesai, program menambahkan satu bintang di bagian paling bawah sebagai ujung penutup.
##### Output 1
![Screenshot Output 1](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/ac637e1161dffcb3fdbf5fba38137657016bb75f/MODUL%201/foto%20output/Screenshot%202025-12-30%20103830.png)

##### Output 2
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/ca1798b4651b1354f1c3d561d6122a4a0af167ff/MODUL%201/foto%20output/Screenshot%202025-12-30%20104241.png)

##### Output 3
![Screenshot Output 3](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/ca1798b4651b1354f1c3d561d6122a4a0af167ff/MODUL%201/foto%20output/Screenshot%202025-12-30%20104557.png)


## Kesimpulan
Secara keseluruhan, rangkaian kode ini menunjukkan perkembangan pemahaman logika pemrograman C++ yang dimulai dari penguasaan operasi aritmatika dasar dan input-output pada program kalkulator. Kemudian, pemahaman tersebut meningkat pada penggunaan logika kondisional (if-else) dan array untuk menerjemahkan data angka menjadi teks, hingga akhirnya mencapai tahap manipulasi alur program yang lebih kompleks menggunakan perulangan bersarang (nested loops) untuk membentuk pola visual yang presisi. Ketiga materi ini merupakan fondasi utama dalam pemrograman untuk membangun aplikasi yang mampu menghitung, mengambil keputusan, dan melakukan tugas otomatis secara berulang.

## Referensi
[1] W3Schools C++ Tutorial:https://www.w3schools.com/cpp/

[2] GeeksforGeeks C++ Programming https://www.geeksforgeeks.org/cpp-tutorial/

[3] Programiz C++ Control Flow : https://www.programiz.com/cpp-programming/if-else

[4] LearnCpp.com: https://www.learncpp.com/

