#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node *next;
};

Node *head = NULL;

void tampilkanLinkedList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void tambahDiAwal(int nilai) {
    Node *newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = head;
    head = newNode;
    tampilkanLinkedList();
}

void tambahDiAkhir(int nilai) {
    Node *newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    tampilkanLinkedList();
}

void tambahSetelah(int nilaiBaru, int nilaiDicari) {
    Node *temp = head;
    
    while (temp != NULL && temp->nilai != nilaiDicari) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        Node *newNode = new Node();
        newNode->nilai = nilaiBaru;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Nilai " << nilaiDicari << " tidak ditemukan dalam list.\n";
    }
    tampilkanLinkedList();
}

void hapusBerdasarkanNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong!\n";
        return;
    }
    
    if (head->nilai == nilai) {
        Node *temp = head;
        head = head->next;
        delete temp;
        tampilkanLinkedList();
        return;
    }
    
    Node *temp = head;
    Node *prev = NULL;
    
    while (temp != NULL && temp->nilai != nilai) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp != NULL) {
        prev->next = temp->next;
        delete temp;
    } else {
        cout << "Nilai " << nilai << " tidak ditemukan dalam list.\n";
    }
    tampilkanLinkedList();
}

int main() {
    int pilihan, nilai, nilaiDicari;
    
    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAwal(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAkhir(nilai);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiDicari;
                tambahSetelah(nilai, nilaiDicari);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusBerdasarkanNilai(nilai);
                break;
            case 5:
                tampilkanLinkedList();
                break;
            case 0:

                while (head != NULL) {
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                }
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}