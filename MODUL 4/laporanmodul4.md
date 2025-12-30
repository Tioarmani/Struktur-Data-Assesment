# <h1 align="center">Laporan Praktikum Modul 4 Singly Linked List(1)</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Singly Linked List (SLL) adalah struktur data yang tersusun dari sekumpulan elemen atau node yang saling terhubung dalam satu arah menggunakan pointer. Berbeda dengan array yang membutuhkan blok memori berurutan, SLL menyimpan data secara dinamis di lokasi memori yang terpisah, di mana setiap node terdiri dari dua bagian utama: Data sebagai penyimpan informasi dan Pointer sebagai penghubung ke node selanjutnya. Rangkaian ini dimulai dari pointer First yang menandai awal list dan diakhiri dengan pointer NULL pada node terakhir untuk menunjukkan batas akhir struktur.
Dalam operasionalnya, SLL mendukung berbagai fungsi dasar, mulai dari inisialisasi list kosong hingga manajemen memori melalui alokasi dan dealokasi node. Pengguna dapat memanipulasi data secara fleksibel melalui operasi Insert (penambahan) dan Delete (penghapusan) baik di posisi awal, tengah, maupun akhir rangkaian. Selain itu, tersedia pula fitur Searching untuk menemukan data spesifik serta Print Info untuk menelusuri seluruh isi elemen. Keunggulan utama SLL terletak pada sifatnya yang dinamis, yang memungkinkan ukuran penyimpanan bertambah atau berkurang sewaktu-waktu tanpa perlu menetapkan kapasitas tetap di awal program.
### Guided 

### 1. Linked List 1
#### mainguided1.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
#### listguided1.cpp
```C++
#include "list1.h"
#include <iostream>
using namespace std;


bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### list1.h
```C++

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Ketiga berkas tersebut membentuk satu kesatuan sistem untuk mengelola Singly Linked List dengan data bertipe mahasiswa. Berkas list1.h berfungsi sebagai kerangka utama yang mendefinisikan struktur data mahasiswa dan node, serta memuat prototipe seluruh fungsi operasi list. Selanjutnya, logika teknis dari fungsi-fungsi tersebut, seperti pembuatan list, alokasi memori, hingga prosedur penambahan elemen (insert), dijabarkan secara detail di dalam berkas listguided1.cpp. Sebagai penutup, berkas mainguided1.cpp berperan sebagai program utama yang menggerakkan seluruh sistem; di sini dilakukan proses inisialisasi, pengisian data ke dalam node, dan pemanggilan prosedur untuk menampilkan hasil akhir guna memastikan seluruh fungsi berjalan dengan benar.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi( input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst( input/output L : List, input P : address )
```
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
```C++
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    
    return 0;
}
```
### KODE PROGRAM
#### main.cpp
```C++
#include "ungu1singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

    createList(&L);

    P1 = alokasi(2);
    insertFirst(&L, P1);

    P2 = alokasi(0);
    insertFirst(&L, P2);

    P3 = alokasi(8);
    insertFirst(&L, P3);

    P4 = alokasi(12);
    insertFirst(&L, P4);

    P5 = alokasi(9);
    insertFirst(&L, P5);

    printInfo(L);

    // Bagian tambahan untuk membersihkan memori (dealokasi semua elemen)
    address current = L.First;
    address temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        dealokasi(temp);
    }
    L.First = NULL;

    return 0;
}
```
#### list.cpp
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### Output 1
![Screenshot Output 1](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/6fb354a0dcff3f5365032203de2bf0b8cf0cbcf0/MODUL%204/hasil%20output/Screenshot%202025-12-30%20124304.png)

Program ini merupakan contoh dasar dari pembuatan Singly Linked List yang digunakan untuk menyimpan sekumpulan angka bulat (integer). Secara teknis, program ini bekerja dengan membuat beberapa node secara dinamis di memori melalui fungsi alokasi, lalu setiap angka (9, 12, 8, 0, 2) dimasukkan ke dalam daftar menggunakan prosedur insertFirst. Karena setiap angka baru selalu diletakkan di posisi paling depan (ujung First), maka hasil urutan angka saat ditampilkan akan terbalik dari urutan pemanggilannya di dalam kode. Program ini juga sudah dilengkapi dengan mekanisme pembersihan memori (dealokasi) di bagian akhir untuk memastikan tidak ada penggunaan memori yang sia-sia setelah program selesai berjalan.


### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

#### main.cpp
```C++
// File: unguided1main.cpp

#include "ungu2singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(&L);

    P1 = alokasi(2); insertFirst(&L, P1);
    P2 = alokasi(0); insertFirst(&L, P2);
    P3 = alokasi(8); insertFirst(&L, P3);
    P4 = alokasi(12); insertFirst(&L, P4);
    P5 = alokasi(9); insertFirst(&L, P5);

    cout << "List Awal (untuk verifikasi): ";
    printInfo(L);
    cout << endl << endl;

    address P_del;
    
    deleteFirst(&L, &P_del);
    dealokasi(P_del);
    
    deleteLast(&L, &P_del); 
    dealokasi(P_del);
    
    address Prec = search(L, 12); 

    if (Prec != NULL && Prec->next != NULL && Prec->next->info == 8) {
        deleteAfter(&L, &P_del, Prec);
        dealokasi(P_del);
    }

    printInfo(L);
    cout << endl; 
    
    cout << "Jumlah node : " << nbList(L) << endl; 

    deleteList(&L);
    cout << endl << "- List Berhasil Terhapus -" << endl;

    cout << "Jumlah node : " << nbList(L) << endl; 

    return 0;
}
```
#### list.cpp
```C++
// File: unguided1list.cpp

#include "ungu2singlist.h"
#include <iostream>

using namespace std;

void createList(List *L) {
    (*L).First = NULL;
}

address alokasi(infotype X) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List *L, address P) {
    if (P != NULL) {
        P->next = (*L).First;
        (*L).First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) return; 

    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}

address search(List L, infotype X) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteFirst(List *L, address *P) {
    *P = (*L).First;
    if (*P != NULL) {
        (*L).First = (*L).First->next;
        (*P)->next = NULL; 
    }
}

void deleteLast(List *L, address *P) {
    address Last = (*L).First;
    address Prec = NULL;
    
    if (Last != NULL && Last->next == NULL) {
        *P = Last;
        (*L).First = NULL;
        return;
    }

    while (Last != NULL && Last->next != NULL) {
        Prec = Last;
        Last = Last->next;
    }

    if (Last != NULL) {
        *P = Last;
        Prec->next = NULL;
    }
}

void deleteAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        (*Pdel)->next = NULL;
    } else {
        *Pdel = NULL;
    }
}

void deleteList(List *L) {
    address P;
    while ((*L).First != NULL) {
        deleteFirst(L, &P);
        dealokasi(P);
    }
}
```
#### singlylist.h
```C++
// File: unguided1list.h

#ifndef UNGUIDED1LIST_H
#define UNGUIDED1LIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

int nbList(List L);
address search(List L, infotype X); 
void deleteFirst(List *L, address *P);
void deleteLast(List *L, address *P);
void deleteAfter(List *L, address *Pdel, address Prec);
void deleteList(List *L);

#endif // UNGUIDED1LIST_H
```

#### Output 2
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/6fb354a0dcff3f5365032203de2bf0b8cf0cbcf0/MODUL%204/hasil%20output/Screenshot%202025-12-30%20124739.png)

Program ini merupakan pengembangan dari materi sebelumnya yang berfokus pada operasi penghapusan dan pencarian pada Singly Linked List. Di dalam program utama, setelah lima angka dimasukkan ke posisi depan, program melakukan serangkaian aksi modifikasi, yaitu menghapus elemen pertama menggunakan deleteFirst, menghapus elemen terakhir melalui deleteLast, serta mencari angka spesifik (angka 12) untuk menghapus elemen yang berada tepat di belakangnya dengan fungsi deleteAfter. Selain itu, program ini dilengkapi dengan fitur statistik seperti nbList untuk menghitung jumlah total data yang tersisa dan fungsi deleteList yang bertugas membersihkan seluruh isi daftar sekaligus guna memastikan manajemen memori yang aman.



## Kesimpulan
Implementasi ini menunjukkan penguasaan struktur data dinamis yang komprehensif melalui pengembangan Singly Linked List yang bersifat modular dan terukur. Program ini secara efektif mengintegrasikan mekanisme manajemen memori dinamis menggunakan fungsi alokasi dan dealokasi yang disiplin guna menjamin efisiensi penggunaan sumber daya serta mencegah risiko kebocoran memori (memory leak).
Keberhasilan dalam menyusun berbagai operasi tingkat lanjut, seperti penghapusan elemen di berbagai posisi (first, last, after) dan fungsi pencarian data, membuktikan pemahaman yang matang mengenai manipulasi pointer dan navigasi struktur data satu arah. Selain itu, pemisahan kode ke dalam berkas header, implementasi, dan driver menunjukkan penerapan standar profesional dalam pengembangan perangkat lunak yang mengutamakan kemudahan pemeliharaan kode serta skalabilitas sistem untuk pengembangan di masa depan.
