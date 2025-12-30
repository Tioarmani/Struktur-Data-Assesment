
# <h1 align="center">Laporan Praktikum Modul 10 - tree(bagian pertama)</h1>
<p align="center">Tio Armani - 103112430225</p>

## Dasar Teori
Berbeda dengan struktur data linear seperti list, stack, atau queue, Tree (Pohon) merupakan model data non-linear yang menyerupai graf terhubung tanpa adanya siklus. Sebuah struktur dapat diklasifikasikan sebagai pohon jika memenuhi tiga karakteristik utama: pertama, pohon dianggap hampa jika tidak memiliki elemen; kedua, memiliki satu titik pusat di puncak yang disebut Akar (Root) sebagai titik awal tanpa pendahulu; dan ketiga, setiap elemen pendukung atau Node hanya diizinkan memiliki tepat satu atasan atau orang tua (Parent).
Materi Utama: Binary Search Tree (BST)
Fokus pembahasan ini adalah pada Binary Search Tree (BST), yakni jenis pohon biner yang datanya ditempatkan secara teratur berdasarkan perbandingan nilai untuk mempercepat proses pengolahan.
1. Penyisipan (Insert) Proses penambahan elemen dilakukan dengan logika perbandingan: nilai baru yang lebih kecil dari node saat ini akan diarahkan ke sub-pohon kiri (Left Subtree), sedangkan nilai yang lebih besar akan diletakkan pada sub-pohon kanan (Right Subtree).
2. Pencarian (Search) Pencarian dilakukan secara rekursif mulai dari akar dengan membandingkan nilai target: jika tidak cocok, penunjuk (pointer) akan bergerak ke cabang kiri untuk nilai yang lebih kecil atau ke cabang kanan untuk nilai yang lebih besar hingga data ditemukan atau mencapai titik kosong (NULL).
3. Penghapusan (Delete) Terdapat tiga skenario teknis dalam menghapus node:
Node Daun (Leaf): Dapat langsung dihapus tanpa memengaruhi struktur lain.
Node dengan 1 Anak: Posisi node yang dihapus akan langsung digantikan oleh posisi anaknya.
Node dengan 2 Anak: Posisi kosong akan diisi oleh nilai terbesar dari sub-pohon kiri atau nilai terkecil dari sub-pohon kanan untuk menjaga aturan BST.
4. Elemen Paling Kiri (Most Left) Merupakan node di posisi ujung kiri bawah yang merepresentasikan nilai terkecil dalam BST, ditemukan dengan menelusuri cabang kiri hingga habis.
5. Elemen Paling Kanan (Most Right) Merupakan node di posisi ujung kanan bawah yang mewakili nilai terbesar dalam BST, ditemukan dengan menelusuri cabang kanan hingga habis.

### GUIDED 1
### [Binary Searh Tree] 

### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; 

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree; 

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

void createTree(BinTree &tree) {
    tree = Nil;
}

node alokasi(int angkaInput) {
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan!" << endl;
    } else if (nodeBaru->angka < tree->angka) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->angka > tree->angka) {
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari) {
    if (isEmpty(tree)) {
        cout << "Tree kosong!" << endl;
        return;
    }
    node nodeBantu = tree;
    node parent = Nil;
    bool ketemu = false;
    while (nodeBantu != Nil) {
        if (angkaCari < nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->left;
        } else if (angkaCari > nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->right;
        } else {
            ketemu = true;
            break;
        }
    }
    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        cout << "Data ditemukan!" << endl;
        cout << "Parent: " << (parent ? to_string(parent->angka) : "- (Root)") << endl;
        cout << "Child kiri: " << (nodeBantu->left ? to_string(nodeBantu->left->angka) : "-") << endl;
        cout << "Child kanan: " << (nodeBantu->right ? to_string(nodeBantu->right->angka) : "-") << endl;
    }
}

void preOrder(BinTree tree) {
    if (tree != Nil) {
        cout << tree->angka << " - ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << tree->angka << " - ";
        inOrder(tree->right);
    }
}

void postOrder(BinTree tree) {
    if (tree != Nil) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->angka << " - ";
    }
}

node mostLeft(BinTree tree) {
    while (tree && tree->left != Nil) tree = tree->left;
    return tree;
}

node mostRight(BinTree tree) {
    while (tree && tree->right != Nil) tree = tree->right;
    return tree;
}

bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) return false;
    if (angka < tree->angka) return deleteNode(tree->left, angka);
    if (angka > tree->angka) return deleteNode(tree->right, angka);
    
    node tmp = tree;
    if (tree->left == Nil) {
        tree = tree->right;
        dealokasi(tmp);
    } else if (tree->right == Nil) {
        tree = tree->left;
        dealokasi(tmp);
    } else {
        node successor = mostLeft(tree->right);
        tree->angka = successor->angka;
        return deleteNode(tree->right, successor->angka);
    }
    return true;
}

void deleteTree(BinTree &tree) {
    if (tree != Nil) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree) {
    return (tree == Nil) ? 0 : 1 + size(tree->left) + size(tree->right);
}

int height(BinTree tree) {
    if (tree == Nil) return -1;
    return 1 + max(height(tree->left), height(tree->right));
}
```
### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);
    int pilih, angka;

    do {
        cout << "\n========= MENU BST =========" << endl;
        cout << "1. Insert | 2. Delete | 3. Search | 4. PreOrder | 5. InOrder | 6. PostOrder" << endl;
        cout << "7. Size   | 8. Height | 9. MostRight | 10. MostLeft | 11. Clear | 0. Exit" << endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih) {
            case 1: cout << "Angka: "; cin >> angka; insertNode(tree, alokasi(angka)); break;
            case 2: cout << "Hapus: "; cin >> angka; deleteNode(tree, angka); break;
            case 3: cout << "Cari: "; cin >> angka; searchByData(tree, angka); break;
            case 4: preOrder(tree); break;
            case 5: inOrder(tree); break;
            case 6: postOrder(tree); break;
            case 7: cout << "Size: " << size(tree); break;
            case 8: cout << "Height: " << height(tree); break;
            case 9: if(tree) cout << "MostRight: " << mostRight(tree)->angka; break;
            case 10: if(tree) cout << "MostLeft: " << mostLeft(tree)->angka; break;
            case 11: deleteTree(tree); break;
        }
    } while (pilih != 0);
    return 0;
}
   
```
Program ini mengimplementasikan struktur data Binary Search Tree (BST), yaitu sebuah pohon biner di mana setiap datanya disimpan secara terorganisir. Aturan utamanya sederhana: untuk setiap "cabang" atau node, angka yang lebih kecil akan selalu diletakkan di sebelah kiri, sedangkan angka yang lebih besar akan diletakkan di sebelah kanan. Hal ini membuat proses pencarian data menjadi sangat cepat karena kita tidak perlu mengecek seluruh isi pohon.
## Unguided

## soal 1. 
### bstree.h
```c++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// alokasi node
address alokasi(infotype x);

// insert node ke BST
void insertNode(address &root, infotype x);

// mencari node
address findNode(infotype x, address root);

// traversal inorder
void InOrder(address root);

#endif
```
### bstree.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

// fungsi alokasi
address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

// fungsi insert BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika sama → tidak dimasukkan
}

// fungsi cari node
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x)
        return root;
    if (x < root->info)
        return findNode(x, root->left);
    return findNode(x, root->right);
}

// traversal InOrder
void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}


```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    return 0;
}
```
### Output soal 1 :
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/d53581bd43ad933f601a1b4ec3f3c722e677f2f7/MODUL%2010/hasil%20output/Screenshot%202025-12-30%20174518.png)

Program ini mengimplementasikan Binary Search Tree (BST), yaitu struktur data pohon biner yang menyimpan angka secara otomatis berdasarkan nilainya. Setiap data dibungkus dalam sebuah Node yang memiliki dua cabang, yaitu cabang kiri untuk menyimpan angka yang lebih kecil dan cabang kanan untuk angka yang lebih besar dari induknya.

### soal 2.

### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif

```
### bstree.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil)
        return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil)
        return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/d53581bd43ad933f601a1b4ec3f3c722e677f2f7/MODUL%2010/hasil%20output/Screenshot%202025-12-30%20174534.png)

Program ini mengimplementasikan struktur data Binary Search Tree (BST), sebuah model pohon biner yang menyimpan angka-angka secara otomatis berdasarkan nilainya. Setiap data dibungkus dalam sebuah Node yang memiliki dua cabang utama: cabang kiri untuk menyimpan nilai yang lebih kecil dan cabang kanan untuk nilai yang lebih besar dari induknya. Penempatan yang teratur ini memungkinkan program untuk melakukan pencarian dan pengolahan data dengan sangat cepat.
### soal 3. [alternatif 3]
### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif

```
### bstree.cpp
```c++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    
    cout << "Tampilkan preOrder : " ;
    preOrder(root); 
    cout << endl;
    
    cout << "Tampilkan postOrder : "; 
    postOrder(root);
    cout << endl;
    
    return 0;
}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Tioarmani/Struktur-Data-Assesment/blob/d53581bd43ad933f601a1b4ec3f3c722e677f2f7/MODUL%2010/hasil%20output/Screenshot%202025-12-30%20174550.png)

Program ini mengimplementasikan struktur data Binary Search Tree (BST), sebuah model penyimpanan data non-linear yang sangat efisien untuk proses pencarian dan pengurutan angka. Setiap angka disimpan dalam sebuah Node yang memiliki dua jalur penghubung: cabang kiri untuk menyimpan nilai yang lebih kecil dan cabang kanan untuk nilai yang lebih besar dari induknya. Seluruh data dikelola menggunakan alokasi memori dinamis, yang berarti ruang penyimpanan hanya akan digunakan saat data baru benar-benar dimasukkan ke dalam pohon.

### Kesimpulan
Binary Search Tree (BST) merupakan struktur data non-linear yang mengorganisir data secara hierarkis. BST sangat unggul dalam efisiensi pencarian karena setiap langkah pencarian memangkas setengah dari jalur yang ada (jika pohon seimbang). Berdasarkan kode yang dijalankan, BST tidak hanya berfungsi sebagai wadah penyimpanan, tetapi juga alat pengurutan data otomatis melalui metode penelusuran In-Order. Fitur pengukuran seperti hitungKedalaman dan hitungTotal memberikan kemampuan analisis dimensi data yang komprehensif.
