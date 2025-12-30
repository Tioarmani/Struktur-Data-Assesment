# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Tio Armani - 103112430225</p>

## DASAR TEORI
Kebutuhan perangkat lunak merupakan fondasi utama sebuah sistem yang merinci seluruh fungsi, fitur, serta batasan operasional yang harus dipenuhi. Secara garis besar, kebutuhan ini terbagi menjadi dua kategori, yaitu kebutuhan fungsional yang menjelaskan tindakan spesifik sistem seperti mengolah data atau mencetak laporan, serta kebutuhan non-fungsional yang mengatur aspek kualitas seperti kecepatan, keamanan, dan kemudahan penggunaan.
Dalam sistem operasi, sebuah program yang sedang berjalan dikenal sebagai proses, yang merupakan unit aktivitas utama di bawah kendali sistem. Setiap proses dikelola menggunakan Process Control Block (PCB) sebagai tempat penyimpanan data teknis dan status proses tersebut. Selama masa aktifnya, sebuah proses akan berpindah melalui berbagai status, mulai dari tahap pembuatan (New), persiapan (Ready), pelaksanaan (Running), penundaan karena hambatan tertentu (Blocked), hingga tahap akhir ketika tugas selesai (Exit).
Guna mendukung kinerja banyak tugas secara serentak, sistem operasi menerapkan mekanisme Context Switching untuk perpindahan kendali CPU antar-proses secara cepat. Selain itu, digunakan pula teknik Swapping untuk memindahkan data dari memori utama ke cakram penyimpanan apabila kapasitas memori sudah penuh.

### 1. ...

```C++
#include <iostream>
using namespace std;

const int SIZE = 3;

void inputMatriks(int mat[SIZE][SIZE]) {
    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void tampilkanMatriks(int mat[SIZE][SIZE]) {
    cout << "Matriks:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void penjumlahan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pengurangan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalian(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[SIZE][SIZE], matriksB[SIZE][SIZE], hasil[SIZE][SIZE];
    int pilihan;

    cout << "=== Program Operasi Matriks 3x3 ===\n";
    inputMatriks(matriksA);
    cout << "\nMatriks A:\n";
    tampilkanMatriks(matriksA);

    inputMatriks(matriksB);
    cout << "\nMatriks B:\n";
    tampilkanMatriks(matriksB);

    cout << "\nPilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            penjumlahan(matriksA, matriksB, hasil);
            cout << "\nHasil Penjumlahan:\n";
            tampilkanMatriks(hasil);
            break;
        case 2:
            pengurangan(matriksA, matriksB, hasil);
            cout << "\nHasil Pengurangan:\n";
            tampilkanMatriks(hasil);
            break;
        case 3:
            perkalian(matriksA, matriksB, hasil);
            cout << "\nHasil Perkalian:\n";
            tampilkanMatriks(hasil);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}


```
penjelasan singkat 1
Program ini merupakan aplikasi berbasis konsol untuk mengolah matriks dua dimensi berukuran 3x3 dengan menggunakan konsep fungsi (void) agar kode lebih terstruktur. Di awal program, pengguna diminta untuk menginput nilai setiap elemen untuk dua buah matriks (Matriks A dan B) melalui perulangan bersarang. Setelah data tersimpan, program menyediakan menu pilihan operasi menggunakan struktur switch-case, di mana setiap pilihan akan memicu fungsi matematika yang berbeda: penjumlahan dan pengurangan dilakukan dengan mengoperasikan elemen pada posisi yang sama, sedangkan perkalian menggunakan algoritma perkalian matriks yang melibatkan penjumlahan hasil kali baris dan kolom.
### 2. ...

```C++

#include <iostream>
using namespace std;

void swapPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void swapReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "=== Swap Menggunakan Pointer ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapPointer(&x, &y, &z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    x = 10; y = 20; z = 30;

    cout << "\n=== Swap Menggunakan Reference ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapReference(x, y, z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    return 0;
}

```
penjelasan singkat 2
Program ini mendemonstrasikan dua metode berbeda untuk menukar nilai antara tiga variabel dalam C++, yaitu menggunakan Pointer dan Reference. Pada metode pertama, fungsi swapPointer menerima alamat memori dari variabel sehingga perubahan nilai dilakukan langsung pada lokasi memori aslinya menggunakan operator dereferensi (*). Sementara itu, metode kedua melalui fungsi swapReference menggunakan alias atau nama lain dari variabel tersebut (&), yang memungkinkan manipulasi nilai variabel secara langsung tanpa perlu mengirimkan alamat memorinya secara eksplisit. Keduanya menghasilkan efek yang sama, yakni menggeser nilai variabel secara sirkular (x ke y, y ke z, dan z kembali ke x), namun dibedakan oleh cara penulisan sintaksis dan mekanisme pengaksesan memorinya.


### 3. ...

```C++

#include <iostream>
using namespace std;

const int UKURAN = 10;
int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

int cariMinimum() {
    int min = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] < min) {
            min = arrA[i];
        }
    }
    return min;
}

int cariMaksimum() {
    int max = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] > max) {
            max = arrA[i];
        }
    }
    return max;
}

void hitungRataRata() {
    float sum = 0;
    for (int i = 0; i < UKURAN; i++) {
        sum += arrA[i];
    }
    float rataRata = sum / UKURAN;
    cout << "Rata-rata: " << rataRata << endl;
}

// Fungsi tampilkan isi array
void tampilkanArray() {
    cout << "Isi array: ";
    for (int i = 0; i < UKURAN; i++) {
        cout << arrA[i] << " ";
    }
    cout << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray();
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum() << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum() << endl;
                break;
            case 4:
                hitungRataRata();
                break;
            case 0:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
```
penjelasan singkat  3
Program ini merupakan aplikasi berbasis menu yang dirancang untuk menganalisis data statistik sederhana di dalam sebuah array berukuran sepuluh elemen. Dengan menggunakan struktur perulangan do-while dan kontrol switch-case, program memungkinkan pengguna untuk berulang kali memilih opsi operasi seperti menampilkan seluruh isi data, mencari nilai tertinggi dan terendah melalui proses pembandingan elemen satu per satu, serta menghitung nilai rata-rata dari total keseluruhan data. Secara teknis, program ini memisahkan setiap tugas logika ke dalam fungsi-fungsi khusus guna mempermudah pemeliharaan kode dan memastikan aliran program berjalan secara sistematis berdasarkan input pengguna.

##### Output 1
![Screenshot Output 1](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/b0bbff1af2f43a8f9cec1c8033381e1b7c010e13/MODUL%202/foto%20output/Screenshot%202025-12-30%20105634.png)

##### Output 2
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/b0bbff1af2f43a8f9cec1c8033381e1b7c010e13/MODUL%202/foto%20output/Screenshot%202025-12-30%20110253.png)

##### Output 3
![Screenshot Output 3](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/85143defde9dc513338d75ce4f5ca71c3eb553ee/MODUL%202/foto%20output/Screenshot%202025-12-30%20110604.png)


## Kesimpulan
Ketiga program tersebut menunjukkan penguasaan Anda pada konsep pemrograman C++ yang lebih lanjut, di mana fokus utama beralih dari sekadar input-output dasar menuju pengelolaan struktur data dan efisiensi memori. Melalui program matriks, Anda telah mempraktikkan penggunaan array dua dimensi untuk menyelesaikan persoalan matematis yang kompleks. Program penukaran nilai memperlihatkan pemahaman mendalam tentang manajemen alamat memori melalui pointer dan reference, yang merupakan fitur kunci untuk mengoptimalkan performa program. Terakhir, program statistik array membuktikan kemampuan Anda dalam membangun aplikasi interaktif yang modular, di mana logika perhitungan dipisahkan ke dalam fungsi-fungsi khusus agar kode lebih rapi, mudah dibaca, dan dapat digunakan kembali.

## Referensi
[1] W3Schools - C++ Loops: https://www.w3schools.com/cpp/cpp_while_loop.asp

[2] GeeksforGeeks - Finding Maximum and Minimum in an Array: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

[3] Programiz - C++ For Loop: https://www.programiz.com/cpp-programming/for-loop



