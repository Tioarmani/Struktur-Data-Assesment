# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Stack atau tumpukan merupakan sebuah model struktur data linear yang bekerja dengan prinsip satu pintu akses tunggal yang dikenal sebagai Top (puncak). Struktur ini menerapkan aturan LIFO (Last In, First Out), yang berarti elemen data yang terakhir kali dimasukkan akan menjadi data yang pertama kali diproses atau dikeluarkan. Secara logis, sistem ini bekerja layaknya tumpukan benda di dunia nyata, di mana elemen yang berada di posisi paling bawah hanya dapat diakses setelah seluruh elemen di atasnya disingkirkan secara berurutan.

A. Operasi Fundamental pada Arsitektur Stack Dalam perancangan arsitektur Stack, terdapat dua operasi utama yang menjadi fondasi pengolahan data, yaitu prosedur penambahan dan pengambilan elemen.

1. Operasi Push (Penyisipan) Instruksi Push digunakan untuk menaruh atau menyisipkan data baru pada posisi puncak tumpukan. Namun, sebelum data ditambahkan, sistem akan melakukan pengecekan kapasitas; jika ruang penyimpanan sudah mencapai batas maksimum, maka perintah akan dibatalkan untuk menghindari kegagalan sistem yang disebut sebagai Overflow.

2. Operasi Pop (Pengambilan) Fungsi Pop bertugas untuk mengidentifikasi sekaligus menghapus elemen yang saat itu berada di posisi teratas. Operasi ini hanya dapat dieksekusi apabila tumpukan berisi data. Jika sistem diperintahkan untuk menghapus elemen pada kondisi tumpukan yang benar-benar hampa, maka akan terjadi error atau kegagalan fungsi yang dikenal dengan istilah Underflow.
## Guided 1

### . [stack menggunakan linked list] 

### stack.h
```C++

#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

//ubah kapasitas sesuai kebutuhan
using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
   
```
Program ini mengimplementasikan struktur data Stack yang bekerja dengan prinsip LIFO (Last In, First Out). Penggunaan Linked List sebagai basisnya membuat ukuran tumpukan menjadi dinamis (tidak terbatas kapasitas array), di mana penambahan dan pengambilan data selalu dilakukan melalui satu pintu akses saja, yaitu pointer Top.


## Guided 1

### . [Stack menggunakan fungsi array] 

### stack.h
```C++

#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

```
Berbeda dengan implementasi berbasis linked list, program ini menggunakan array dengan kapasitas tetap (MAX = 10). Struktur ini dikelola oleh satu variabel penunjuk bernama top. Variabel top berfungsi sebagai indeks penanda posisi elemen terakhir yang dimasukkan. Jika top bernilai -1, itu berarti tumpukan benar-benar kosong.
## Unguided

## Soal 1
### stack.h
```C++

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output soal 1 :
![Screenshot Output 1](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/76edc83227d26b69fda3a7cf30869c2da88fcc89/MODUL%207/hasil%20output/Screenshot%202025-12-30%20161858.png)

Program ini mengimplementasikan struktur data Stack atau tumpukan menggunakan media Array statis dengan kapasitas maksimal 20 elemen. Prinsip utama yang digunakan adalah LIFO (Last In, First Out), di mana data yang terakhir kali dimasukkan akan menjadi data pertama yang diproses, dengan variabel top sebagai satu-satunya pintu kendali untuk melacak posisi elemen paling atas.

### soal 2. 

### stack.h
```C++

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

```
### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    return 0;
}

```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/76edc83227d26b69fda3a7cf30869c2da88fcc89/MODUL%207/hasil%20output/Screenshot%202025-12-30%20162004.png)

Program ini menggunakan struktur data Stack yang bekerja dengan prinsip LIFO (Last In, First Out), di mana data yang terakhir masuk akan menjadi yang pertama kali keluar. Bayangkan seperti tumpukan piring; Anda menaruh piring di atas dan mengambilnya pun dari paling atas. Kendali utama tumpukan ini ada pada variabel Top yang berfungsi sebagai penanda posisi elemen tertinggi.
### soal 3.
### stack.h
```C++

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);
void getInputStream(Stack &S);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    createStack(S);

    char n;
    while(true){
        n = cin.get();
        if(n == '\n') {
            break;
        }
        if(n >= '0' && n <= '9' ) {
            int val = n - '0';
            push(S, val);
        }
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/76edc83227d26b69fda3a7cf30869c2da88fcc89/MODUL%207/hasil%20output/Screenshot%202025-12-30%20162037.png)

Program ini menggunakan konsep Stack atau tumpukan yang diimplementasikan melalui Array statis berkapasitas 20 elemen. Logika utamanya mengikuti prinsip LIFO (Last In, First Out), di mana setiap manipulasi data dipusatkan pada posisi paling atas yang dikendalikan oleh variabel top. Saat tumpukan kosong, variabel top bernilai -1, dan akan terus bertambah seiring masuknya data baru.

### Kesimpulan
Kesimpulan dari ketiga kode tersebut adalah bahwa struktur data Stack dapat diimplementasikan baik menggunakan Linked List maupun Array dengan prinsip LIFO yang fleksibel, di mana program tidak hanya mampu melakukan operasi dasar tambah-kurang, tetapi juga dapat dikembangkan untuk fitur pengurutan otomatis, pembalikan urutan data, hingga pengolahan input stream secara interaktif.


## Referensi
[1] GeeksforGeeks - Stack Data Structure: https://www.geeksforgeeks.org/stack-data-structure/

[2] Programiz - Stack Implementation: https://www.programiz.com/dsa/stack

[3] Cplusplus.com - Stack Container: https://cplusplus.com/reference/stack/stack/
