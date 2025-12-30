
# <h1 align="center">Laporan Praktikum Modul 8 Queue - Stack</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Antrean atau Queue merupakan model struktur data linear yang mengadopsi prinsip pelayanan konvensional, serupa dengan barisan pelanggan di loket. Sistem ini bekerja berdasarkan aturan FIFO (First In, First Out), yang memastikan bahwa elemen data yang pertama kali masuk ke dalam sistem akan menjadi yang pertama pula untuk diproses atau dikeluarkan. Dalam implementasi pemrograman, Queue dapat dibangun menggunakan array dengan kapasitas statis maupun linked list untuk fleksibilitas penyimpanan yang dinamis.

### A. Implementasi Queue 
Berbasis Linked List Penerapan Queue menggunakan linked list menawarkan efisiensi tinggi dalam manipulasi data dibandingkan struktur list standar. Karakteristik teknisnya membatasi titik akses data hanya pada dua ujung: sisi depan (Head) sebagai jalur keluar dan sisi belakang (Tail) sebagai jalur masuk. Struktur ini dapat dikembangkan baik menggunakan Singly Linked List untuk mengoptimalkan memori, maupun Doubly Linked List guna memudahkan navigasi data secara dua arah.

### 1. Operasi Enqueue (Penyisipan) 
Enqueue merupakan prosedur untuk menambahkan elemen baru ke dalam antrean. Setiap data yang masuk akan ditempatkan secara eksklusif pada posisi paling belakang (Tail), sehingga barisan data akan bertambah panjang ke arah belakang sesuai urutan kedatangannya.

### 2. Operasi Dequeue (Penghapusan) 
Dequeue adalah prosedur untuk mengambil atau menghapus elemen dari antrean. Sesuai prinsip FIFO, penghapusan hanya diizinkan pada elemen yang berada di posisi terdepan (Head) guna menjamin urutan pemrosesan data tetap konsisten dan adil.

### GUIDED 1
### [Penggunaan Queue] 

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

```
### queue.cpp
```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

```
### main.cpp
```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
   
   
```
Program ini mengimplementasikan struktur data Queue menggunakan konsep Linked List, di mana setiap data disimpan dalam sebuah "kotak" (Node) yang berisi nama dan alamat data berikutnya. Karena berbasis Linked List, antrean ini bersifat dinamis, artinya kapasitasnya tidak terbatas (fungsi isFull selalu bernilai false) dan memori hanya digunakan saat ada data yang masuk.


## Guided 2
### [Penggunaan Queue dengan beberapa implementasi] 

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama); 
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

```
### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }

```
### main.cpp
```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini mengimplementasikan struktur data antrean menggunakan media Array statis dengan kapasitas maksimal 5 elemen. Berbeda dengan implementasi Linked List, kode ini menggunakan indeks integer head dan tail untuk menandai posisi data paling depan dan paling belakang. Seluruh operasi diatur berdasarkan prinsip FIFO (First In, First Out), yang memastikan data yang pertama kali masuk akan menjadi yang pertama kali dikeluarkan.

## Unguided

## soal 1. [alternatif 1]
### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}
 


int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < Q.head){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output soal 1 :
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/4e4040cf0cc47d665193c6b6a6e34eaa8b451fd6/MODUL%208/hasil%20output/Screenshot%202025-12-30%20170231.png)

Program ini mengimplementasikan struktur data antrean menggunakan Array statis dengan kapasitas maksimal 5 elemen integer. Sistem ini bekerja dengan prinsip FIFO (First In, First Out), yang berarti elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dikeluarkan. Kendali antrean diatur oleh dua variabel indeks, yaitu head untuk menandai elemen terdepan dan tail untuk menandai elemen terakhir yang masuk.

### soal 2. [alternatif 2]

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}


void dequeue(queue &Q){
     if(isEmpty(Q) == true){
         cout << "Queue kosong!" << endl;
     } else {
         Q.head++;
         if(Q.head > Q.tail){
             Q.head = -1;
             Q.tail = -1;
         }
     }
 }

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/4e4040cf0cc47d665193c6b6a6e34eaa8b451fd6/MODUL%208/hasil%20output/Screenshot%202025-12-30%20170412.png)

Program ini mengimplementasikan struktur data antrean menggunakan Array statis dengan kapasitas maksimal 5 elemen integer. Sistem ini bekerja dengan prinsip FIFO (First In, First Out), di mana elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dikeluarkan. Kendali antrean diatur oleh dua variabel indeks, yaitu head untuk menandai elemen terdepan dan tail untuk menandai elemen terakhir yang masuk.

### soal 3. [alternatif 3]
### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q)
{
    if (Q.head == -1 && Q.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(queue Q)
{
    if ((Q.tail + 1) % MAX == Q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createQueue(queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X)
{
    if (isFull(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmpty(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(queue Q)
{
    if (isEmpty(Q) == true)
    {
    cout << Q.head << " - " << Q.tail << " | Empty Queue" << endl;
    return;
    }
    else
    {
        cout << Q.head << " - " << Q.tail << " | ";
        int i = Q.head;
        int count = 1;
        while (true)
        {
            cout << Q.info[i] << " ";

            if (i == Q.tail)
                break;

            cout << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output soal 3:
![Screenshot Output 2]https://github.com/Tioarmani/Struktur-Data-Assesment/blob/4e4040cf0cc47d665193c6b6a6e34eaa8b451fd6/MODUL%208/hasil%20output/Screenshot%202025-12-30%20170454.png)

Program ini mengimplementasikan struktur data Circular Queue menggunakan array statis dengan kapasitas maksimal 5 elemen. Berbeda dengan antrean linear biasa, antrean melingkar memanfaatkan sisa ruang kosong di depan array yang telah ditinggalkan oleh data yang keluar, sehingga penggunaan memori menjadi jauh lebih optimal. Keunikan sistem ini terletak pada penggunaan operator modulo (% MAX) yang memungkinkan indeks head dan tail untuk "berputar" kembali ke angka 0 saat mencapai batas akhir array.

### Kesimpulan
Kesimpulan Program Queue
Ketiga implementasi tersebut menunjukkan bahwa Queue adalah struktur data linear yang bekerja dengan prinsip FIFO (First In, First Out), di mana pengembangannya dapat dilakukan secara dinamis menggunakan Linked List untuk kapasitas tak terbatas, atau secara statis menggunakan Array baik dengan metode pergeseran elemen (Linear) maupun metode perputaran indeks (Circular) untuk mengoptimalkan penggunaan ruang memori yang terbatas.
Poin utama yang dapat dipetik dari kode Anda adalah:
Efisiensi Memori: Circular Queue merupakan solusi paling cerdas dalam penggunaan array karena mampu memanfaatkan kembali slot kosong tanpa perlu menggeser data secara fisik.
Fleksibilitas Struktur: Penggunaan Linked List mempermudah manajemen antrean karena memori hanya digunakan saat ada data yang masuk, serta menghindari risiko antrean penuh (Overflow).

Kontrol Akses: Seluruh kode secara konsisten menjaga integritas antrean dengan membatasi akses masuk hanya melalui Tail dan akses keluar hanya melalui Head.
## Referensi
[1] GeeksforGeeks - Queue Data Structure: https://www.geeksforgeeks.org/queue-data-structure/

[2] Programiz - Circular Queue Data Structure: https://www.programiz.com/dsa/circular-queue

[3]Cplusplus.com - Standard Template Library (std::queue): https://cplusplus.com/reference/queue/queue/

 
