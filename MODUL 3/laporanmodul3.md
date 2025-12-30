# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan sebuah model konseptual yang berfungsi sebagai spesifikasi formal untuk mendefinisikan suatu tipe data beserta kumpulan operasi dasarnya (primitif). Konsep ini bertindak sebagai cetak biru yang tidak hanya merinci struktur data internal, tetapi juga menetapkan aturan mengenai bagaimana fungsi-fungsi tertentu dapat berinteraksi dengan data tersebut. Operasi primitif di dalamnya dikelompokkan berdasarkan tujuannya, seperti fungsi Konstruktor untuk inisialisasi objek, fungsi Selector (seperti Getter) untuk mengakses data, serta berbagai operasi lain untuk keperluan validasi, input/output, maupun perbandingan data.
Dalam penerapannya, prinsip ADT mendukung modularitas dengan memisahkan kode ke dalam dua jenis berkas utama. Berkas header (.h) digunakan sebagai antarmuka yang berisi deklarasi struktur data serta prototipe fungsi-fungsi yang tersedia bagi pengguna. Sementara itu, berkas body (.cpp) menyimpan implementasi teknis dan detail logika dari setiap fungsi tersebut. Dengan pola ini, program utama (driver) hanya perlu memanggil berkas header untuk menggunakan fungsi-fungsi yang tersedia, sehingga tercipta pemisahan yang jelas antara cara penggunaan sistem (antarmuka) dengan detail cara kerja sistem (implementasi).


### 1. ...

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=========================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "=========================================\n";
    cout << "Nama\t\tNIM\t\tNilai Akhir\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << "\t\t"
             << mhs[i].nim << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }

    cout << "=========================================\n";

    return 0;
}

```
Penjelasan singkat 1
Program ini dirancang untuk mengelola data akademik mahasiswa dengan menerapkan konsep Struct (struktur data) guna mengelompokkan berbagai tipe informasi, seperti nama, NIM, dan nilai, ke dalam satu entitas yang sama. Secara teknis, program menggunakan array of struct untuk menampung hingga 10 data mahasiswa dan memanfaatkan sebuah fungsi pendukung bernama hitungNilaiAkhir untuk melakukan kalkulasi otomatis berdasarkan bobot persentase dari nilai UTS, UAS, dan tugas. Di dalam proses inputnya, program menggunakan perintah getline dan cin.ignore untuk memastikan input teks yang mengandung spasi dapat terbaca dengan benar, kemudian diakhiri dengan penyajian seluruh data dalam bentuk tabel ringkas melalui perulangan.

### 2. ...

```h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}


```
penjelasan singkat 2
Program ini merupakan implementasi nyata dari konsep Abstract Data Type (ADT) yang membagi kode ke dalam tiga bagian modular untuk menciptakan organisasi program yang profesional. Bagian pertama adalah berkas Header (pelajaran.h) yang berfungsi sebagai kontrak atau spesifikasi, berisi definisi struktur data dan prototipe fungsi. Bagian kedua adalah berkas Implementasi (pelajaran.cpp) yang menjabarkan logika dari fungsi konstruktor create_pelajaran untuk membuat objek baru dan fungsi tampil_pelajaran untuk menampilkan data. Terakhir, berkas Main Program bertindak sebagai penggerak (driver) yang menggunakan fungsi-fungsi tersebut tanpa perlu mengetahui detail teknis pembuatannya, sehingga memudahkan proses pengembangan dan pemeliharaan kode secara terpisah.

### 3. ...

```C++

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *ptr1, *ptr2;
    ptr1 = &A[1][1];  
    ptr2 = &B[2][2];  
    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarElemen(A, B, 0, 0);

    cout << "\nSetelah menukar elemen A[0][0] dengan B[0][0]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    tukarPointer(ptr1, ptr2);

    cout << "\nSetelah menukar nilai yang ditunjuk pointer:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    return 0;
}




```
penjelasan singkat  3
Program ini mendemonstrasikan dua teknik berbeda untuk menukar nilai antar array dua dimensi (matriks) berukuran 3x3. Metode pertama menggunakan fungsi tukarElemen yang bekerja dengan mengakses indeks baris dan kolom secara langsung untuk menukar nilai pada posisi yang sama di antara dua matriks. Metode kedua menggunakan fungsi tukarPointer, di mana program menukar nilai variabel melalui alamat memori yang ditunjuk oleh pointer; dalam kasus ini, nilai pada posisi A[1][1] ditukar dengan nilai pada B[2][2] tanpa harus mengirimkan seluruh struktur array ke dalam fungsi. Seluruh hasil perubahan data tersebut kemudian ditampilkan secara sistematis menggunakan fungsi tampilkanArray yang memanfaatkan perulangan bersarang.

##### Output 1
![Screenshot Output 1](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/e44b16d742f16c571a263825f3f30f0403a2d447/MODUL%203/foto%20output/Screenshot%202025-12-30%20121058.png)

##### Output 2
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/e44b16d742f16c571a263825f3f30f0403a2d447/MODUL%203/foto%20output/Screenshot%202025-12-30%20121726.png)

##### Output 3
![Screenshot Output 3](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/e44b16d742f16c571a263825f3f30f0403a2d447/MODUL%203/foto%20output/Screenshot%202025-12-30%20122049.png)


## Kesimpulan
Kesimpulan Pemrograman C++
Seluruh implementasi kode ini menunjukkan integrasi fundamental pemrograman C++ yang berfokus pada tiga aspek utama: Pengelolaan Data, Efisiensi Memori, dan Modularitas. Penggunaan Struct dan Array multidimensi memungkinkan penyimpanan data yang kompleks secara terorganisir, sementara penerapan Pointer dan Reference memberikan kontrol penuh terhadap manipulasi data langsung pada alamat memori untuk performa yang lebih optimal.
Selain itu, penerapan konsep Abstract Data Type (ADT) dengan memisahkan berkas menjadi header (.h) dan body (.cpp) membuktikan standar penulisan kode yang profesional. Pendekatan ini memisahkan antara antarmuka dan implementasi, sehingga program menjadi lebih mudah dirawat (maintainable), dapat digunakan kembali (reusable), dan memiliki alur logika yang lebih bersih melalui penggunaan fungsi-fungsi khusus.

## Referensi
[1] GeeksforGeeks - Pointers and 2D Arrays: https://www.geeksforgeeks.org/pointer-array-2d-array-cpp/

[2] W3Schools - C++ Multidimensional Arrays: https://www.w3schools.com/cpp/cpp_arrays_multi.asp

[3] LearnCpp - Pointers and Arrays: https://www.learncpp.com/cpp-tutorial/pointers-and-arrays/
