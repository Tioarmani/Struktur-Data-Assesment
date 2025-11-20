#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std; 
 
// ==================== DEFINISI STRUCT ==================== 
 
struct Product { 
    string Nama; 
    string SKU; 
    int Jumlah; 
    float HargaSatuan; 
    float DiskonPersen; 
}; 
 
struct Node; 
typedef Node* address; 
 
struct Node { 
    Product info; 
    address next; 
}; 
 
struct List { 
    address head; 
}; 
 
// ==================== DEKLARASI FUNGSI/PROSEDUR ==================== 
 
float hitungHargaAkhir(Product P); 
bool isEmpty(List L); 
void createList(List &L); 
address allocate(Product P); 
void deallocate(address addr); 
void insertFirst(List &L, Product P); 
void insertLast(List &L, Product P); 
void insertAfter(List &L, address Q, Product P); 
void deleteFirst(List &L, Product &P); 
void deleteLast(List &L, Product &P); 
void deleteAfter(List &L, address Q, Product &P); 
void updateAtPosition(List &L, int posisi, Product P); 
void viewList(List L); 
void searchByFinalPriceRange(List L, float minPrice, float maxPrice); 
void MaxHargaAkhir(List L); 
 
// ==================== IMPLEMENTASI FUNGSI/PROSEDUR ==================== 
 
float hitungHargaAkhir(Product P) { 
    return P.HargaSatuan * (1 - P.DiskonPersen / 100.0); 
} 
 
bool isEmpty(List L) { 
    return L.head == NULL; 
} 
 
void createList(List &L) { 
    L.head = NULL; 
} 
 
address allocate(Product P) { 
    address newNode = new Node; 
    newNode->info = P; 
    newNode->next = NULL; 
    return newNode; 
} 
 
void deallocate(address addr) { 
    delete addr; 
} 
 
void insertFirst(List &L, Product P) { 
    address newNode = allocate(P); 
    if (isEmpty(L)) { 
        L.head = newNode; 
    } else { 
        newNode->next = L.head; 
        L.head = newNode; 
    } 
} 
 
void insertLast(List &L, Product P) { 
    address newNode = allocate(P); 
    if (isEmpty(L)) { 
        L.head = newNode; 
    } else { 
        address temp = L.head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
void insertAfter(List &L, address Q, Product P) { 
    if (Q == NULL) { 
        cout << "Node Q tidak valid!" << endl; 
        return; 
    } 
    address newNode = allocate(P); 
    newNode->next = Q->next; 
    Q->next = newNode; 
} 
 
void deleteFirst(List &L, Product &P) { 
    if (isEmpty(L)) { 
        cout << "List kosong, tidak ada yang bisa dihapus!" << endl; 
        return; 
    } 
    address temp = L.head; 
    P = temp->info; 
    L.head = L.head->next; 
    deallocate(temp); 
} 
 
void deleteLast(List &L, Product &P) { 
    if (isEmpty(L)) { 
        cout << "List kosong, tidak ada yang bisa dihapus!" << endl; 
        return; 
    } 
     
    if (L.head->next == NULL) { 
        P = L.head->info; 
        deallocate(L.head); 
        L.head = NULL; 
    } else { 
        address temp = L.head; 
        while (temp->next->next != NULL) { 
            temp = temp->next; 
        } 
        P = temp->next->info; 
        deallocate(temp->next); 
        temp->next = NULL; 
    } 
} 
 
void deleteAfter(List &L, address Q, Product &P) { 
    if (Q == NULL || Q->next == NULL) { 
        cout << "Tidak ada node setelah Q atau Q tidak valid!" << endl; 
        return; 
    } 
    address temp = Q->next; 
    P = temp->info; 
    Q->next = temp->next; 
    deallocate(temp); 
} 
 
void updateAtPosition(List &L, int posisi, Product P) { 
    if (isEmpty(L)) { 
        cout << "List kosong!" << endl; 
        return; 
    } 
     
    address temp = L.head; 
    int idx = 1; 
     
    while (temp != NULL && idx < posisi) { 
        temp = temp->next; 
        idx++; 
    } 
     
    if (temp == NULL) { 
        cout << "Posisi " << posisi << " tidak ditemukan!" << endl; 
        return; 
    } 
     
    Product oldData = temp->info; 
    temp->info = P; 
     
    cout << "\n=== Update Data Produk pada Posisi " << posisi << " ===" << endl; 
    cout << "Data lama: " << oldData.Nama << " (SKU: " << oldData.SKU << ")" << endl; 
    cout << "Data baru: " << P.Nama << " (SKU: " << P.SKU << ")" << endl; 
    cout << "Data berhasil diupdate!" << endl; 
} 
 
void viewList(List L) { 
    if (isEmpty(L)) { 
        cout << "List kosong!" << endl; 
        return; 
    } 
     
    cout << "\n--- DAFTAR PRODUK ---" << endl; 
    cout << left << setw(5) << "No"  
         << setw(20) << "Nama"  
         << setw(15) << "SKU"  
         << setw(10) << "Jumlah"  
         << setw(15) << "Harga Satuan"  
         << setw(12) << "Diskon (%)"  
         << setw(15) << "Harga Akhir" << endl; 
    cout << "---------------------" << endl; 
     
    address temp = L.head; 
    int idx = 1; 
     
    while (temp != NULL) { 
        float hargaAkhir = hitungHargaAkhir(temp->info); 
         
        cout << left << setw(5) << idx 
             << setw(20) << temp->info.Nama 
             << setw(15) << temp->info.SKU 
             << setw(10) << temp->info.Jumlah 
             << "Rp " << setw(12) << fixed << setprecision(2) << temp->info.HargaSatuan 
             << setw(12) << temp->info.DiskonPersen 
             << "Rp " << fixed << setprecision(2) << hargaAkhir << endl; 
         
        temp = temp->next; 
        idx++; 
    } 
    cout << "---------------------" << endl; 
} 
 
void searchByFinalPriceRange(List L, float minPrice, float maxPrice) { 
    if (isEmpty(L)) { 
        cout << "List kosong!" << endl; 
        return; 
    } 
     
    cout << "\n--- Pencarian Produk dengan Harga Akhir Rp " << fixed << setprecision(2)  
         << minPrice << " - Rp " << maxPrice << " ---" << endl; 
     
    address temp = L.head; 
    int idx = 1; 
    bool found = false; 
     
    cout << left << setw(5) << "Pos"  
         << setw(20) << "Nama"  
         << setw(15) << "SKU"  
         << setw(10) << "Jumlah"  
         << setw(15) << "Harga Satuan"  
         << setw(12) << "Diskon (%)"  
         << setw(15) << "Harga Akhir" << endl; 
    cout << "---------------------" << endl; 
     
    while (temp != NULL) { 
        float hargaAkhir = hitungHargaAkhir(temp->info); 
         
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) { 
            cout << left << setw(5) << idx 
                 << setw(20) << temp->info.Nama 
                 << setw(15) << temp->info.SKU 
                 << setw(10) << temp->info.Jumlah 
                 << "Rp " << setw(12) << fixed << setprecision(2) << temp->info.HargaSatuan 
                 << setw(12) << temp->info.DiskonPersen 
                 << "Rp " << fixed << setprecision(2) << hargaAkhir << endl; 
            found = true; 
        } 
         
        temp = temp->next; 
        idx++; 
    } 
     
    if (!found) { 
        cout << "Tidak ada produk dalam rentang harga tersebut." << endl; 
    } 
    cout << "---------------------" << endl; 
} 
 
void MaxHargaAkhir(List L) { 
    if (isEmpty(L)) { 
        cout << "List kosong!" << endl; 
        return; 
    } 
     
    address temp = L.head; 
    float maxHarga = hitungHargaAkhir(temp->info); 
     
    while (temp != NULL) { 
        float hargaAkhir = hitungHargaAkhir(temp->info); 
        if (hargaAkhir > maxHarga) { 
            maxHarga = hargaAkhir; 
        } 
        temp = temp->next; 
    } 
     
    cout << "\n--- PRODUK HARGA AKHIR MAKSIMUM ---" << endl; 
    cout << "Harga Akhir Maksimum: Rp " << fixed << setprecision(2) << maxHarga << endl; 
    cout << "------------------------------------" << endl; 
     
    cout << left << setw(5) << "Pos"  
         << setw(20) << "Nama"  
         << setw(15) << "SKU"  
         << setw(10) << "Jumlah"  
         << setw(15) << "Harga Satuan"  
         << setw(12) << "Diskon (%)"  
         << setw(15) << "Harga Akhir" << endl; 
    cout << "------------------------------------" << endl; 
     
    temp = L.head; 
    int idx = 1; 
     
    while (temp != NULL) { 
        float hargaAkhir = hitungHargaAkhir(temp->info); 
         
        if (hargaAkhir == maxHarga) { 
            cout << left << setw(5) << idx 
                 << setw(20) << temp->info.Nama 
                 << setw(15) << temp->info.SKU 
                 << setw(10) << temp->info.Jumlah 
                 << "Rp " << setw(12) << fixed << setprecision(2) << temp->info.HargaSatuan 
                 << setw(12) << temp->info.DiskonPersen 
                 << "Rp " << fixed << setprecision(2) << hargaAkhir << endl; 
        } 
         
        temp = temp->next; 
        idx++; 
    } 
    cout << "------------------------------------" << endl; 
} 
 
// ==================== PROGRAM UTAMA ==================== 
 
int main() { 
    List L; 
    Product P; 
     
    cout << "---" << endl; 
    cout << "   SISTEM INVENTORY TOKO - S1IF-12-042" << endl; 
    cout << "---" << endl; 
     
    // 1. Buat list kosong 
    cout << "\n[1] Membuat list kosong..." << endl; 
    createList(L); 
    cout << "List berhasil dibuat!" << endl; 
     
    // 2. Insert Last 3 produk sesuai soal 
    cout << "\n[2] Menambahkan 3 produk dengan insertLast..." << endl; 
     
    Product p1; 
    p1.Nama = "Pulpen"; 
    p1.SKU = "A001"; 
    p1.Jumlah = 20; 
    p1.HargaSatuan = 2500; 
    p1.DiskonPersen = 0; 
    insertLast(L, p1); 
    cout << "- Pulpen ditambahkan" << endl; 
     
    Product p2; 
    p2.Nama = "Buku Tulis"; 
    p2.SKU = "A002"; 
    p2.Jumlah = 15; 
    p2.HargaSatuan = 5000; 
    p2.DiskonPersen = 10; 
    insertLast(L, p2); 
    cout << "- Buku Tulis ditambahkan" << endl; 
     
    Product p3; 
    p3.Nama = "Penghapus"; 
    p3.SKU = "A003"; 
    p3.Jumlah = 30; 
    p3.HargaSatuan = 1500; 
    p3.DiskonPersen = 0; 
    insertLast(L, p3); 
    cout << "- Penghapus ditambahkan" << endl; 
     
    // 3. Tampilkan list 
    cout << "\n[3] Menampilkan list:" << endl; 
    viewList(L); 
     
    // 4. Delete First 1x 
    cout << "\n[4] Melakukan deleteFirst 1x..." << endl; 
    deleteFirst(L, P); 
    cout << "Produk \"" << P.Nama << "\" (SKU: " << P.SKU << ") berhasil dihapus dari awal list." << 
endl; 
     
    // 5. Tampilkan list kembali 
    cout << "\n[5] Menampilkan list setelah deleteFirst:" << endl; 
    viewList(L); 
     
    // 6. Update data pada posisi ke-2 
    cout << "\n[6] Update data pada posisi ke-2..." << endl; 
    cout << "Data yang akan diinput:" << endl; 
    cout << "Nama         : Stabilo" << endl; 
    cout << "SKU          : A010" << endl; 
    cout << "Jumlah       : 40" << endl; 
    cout << "HargaSatuan  : 9000" << endl; 
    cout << "DiskonPersen : 5" << endl; 
     
    Product pUpdate; 
    pUpdate.Nama = "Stabilo"; 
    pUpdate.SKU = "A010"; 
    pUpdate.Jumlah = 40; 
    pUpdate.HargaSatuan = 9000; 
    pUpdate.DiskonPersen = 5; 
     
    updateAtPosition(L, 2, pUpdate); 
     
    // 7. Tampilkan list setelah update 
    cout << "\n[7] Menampilkan list setelah update:" << endl; 
    viewList(L); 
     
    // 8. Searching berdasarkan HargaAkhir dalam rentang min=2000, max=7000 
    cout << "\n[8] Searching produk dengan HargaAkhir dalam rentang Rp 2000 - Rp 7000:" << 
endl; 
    searchByFinalPriceRange(L, 2000, 7000); 
     
    // BAGIAN B: Panggil MaxHargaAkhir 
    cout << "\n[BAGIAN B] Menampilkan produk dengan HargaAkhir maksimum:" << endl; 
    MaxHargaAkhir(L); 
     
    cout << "\n========================================" << endl; 
    cout << "   PROGRAM SELESAI" << endl; 
    cout << "========================================" << endl; 
     
    return 0; 
} 