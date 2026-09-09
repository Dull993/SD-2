#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int* arr = new int[n]; // Disebut Dynamic Array

    cout << "Masukkan " << n << " angka :\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Isi array : ";
    for( int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; //Memori Hip
    return 0;
}