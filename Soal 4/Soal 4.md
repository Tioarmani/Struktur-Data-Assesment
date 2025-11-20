#include <iostream> 
using namespace std; 
 
// ============================ 
//        STRUCT & ADT 
// ============================ 
 
struct Paket { 
    string KodeResi; 
    string NamaPengirim; 
    int BeratBarang; 
    string Tujuan; 
}; 
 
const int MAX = 5; 
 
struct QueueEkspedisi { 
    Paket dataPaket[MAX]; 
    int Head; 
    int Tail; 
}; 
 
bool isEmpty(QueueEkspedisi &Q) { 
    return (Q.Head == -1 && Q.Tail == -1); 
} 
 
bool isFull(QueueEkspedisi &Q) { 
    return (Q.Tail == MAX - 1); 
} 
 
void createQueue(QueueEkspedisi &Q) { 
    Q.Head = -1; 
    Q.Tail = -1; 
} 
 
void enQueue(QueueEkspedisi &Q, Paket dataBaru) { 
    if (isFull(Q)) { 
        cout << "Queue penuh!" << endl; 
        return; 
    } 
 
    if (isEmpty(Q)) { 
        Q.Head = 0; 
        Q.Tail = 0; 
        Q.dataPaket[0] = dataBaru; 
    } else { 
        Q.Tail++; 
        Q.dataPaket[Q.Tail] = dataBaru; 
    } 
} 
 
void deQueue(QueueEkspedisi &Q) { 
    if (isEmpty(Q)) { 
        cout << "Queue kosong!" << endl; 
        return; 
    } 
 
    if (Q.Head == Q.Tail) { 
        createQueue(Q); 
    } else { 
        Q.Head++; 
    } 
} 
 
void viewQueue(QueueEkspedisi &Q) { 
    if (isEmpty(Q)) { 
        cout << "Queue kosong!" << endl; 
        return; 
    } 
 
    for (int i = Q.Head; i <= Q.Tail; i++) { 
        cout << "Posisi " << i + 1 << endl; 
        cout << "Kode Resi      : " << Q.dataPaket[i].KodeResi << endl; 
        cout << "Nama Pengirim  : " << Q.dataPaket[i].NamaPengirim << endl; 
        cout << "Berat Barang   : " << Q.dataPaket[i].BeratBarang << " kg" << endl; 
        cout << "Tujuan         : " << Q.dataPaket[i].Tujuan << endl << endl; 
    } 
} 
 
int TotalBiayaPengiriman(QueueEkspedisi &Q) { 
    if (isEmpty(Q)) return 0; 
 
    int totalBerat = 0; 
    for (int i = Q.Head; i <= Q.Tail; i++) { 
        totalBerat += Q.dataPaket[i].BeratBarang; 
    } 
    return totalBerat * 8250; 
} 
 
// ============================ 
//            MAIN 
// ============================ 
 
int main() { 
    QueueEkspedisi Q; 
    createQueue(Q); 
 
    int pilihan; 
 
    do { 
        cout << "\n--- Komaniya Ekspress ---\n"; 
        cout << "1. Input Data Paket\n"; 
        cout << "2. Hapus Data Paket (deQueue)\n"; 
        cout << "3. Tampilkan Queue Paket\n"; 
        cout << "4. Hitung Total Biaya Pengiriman\n"; 
        cout << "0. Keluar\n"; 
        cout << "Pilihan anda : "; 
        cin >> pilihan; 
 
        if (pilihan == 1) { 
            Paket P; 
            cout << "Kode Resi      : "; cin >> P.KodeResi; 
            cout << "Nama Pengirim  : "; cin >> P.NamaPengirim; 
            cout << "Berat Barang   : "; cin >> P.BeratBarang; 
            cout << "Tujuan         : "; cin >> P.Tujuan; 
            enQueue(Q, P); 
        } 
 
        else if (pilihan == 2) { 
            deQueue(Q); 
        } 
 
        else if (pilihan == 3) { 
            viewQueue(Q); 
        } 
 
        else if (pilihan == 4) { 
            int total = TotalBiayaPengiriman(Q); 
            cout << "Total Biaya Pengiriman : Rp " << total << endl; 
        } 
 
    } while (pilihan != 0); 
 
    return 0; 
} 
