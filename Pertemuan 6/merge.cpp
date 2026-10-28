#include <iostream>
#include <vector>
using namespace std;

// TODO : Fungsi Bergabung Kembali
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    temp.reserve(right - left + 1);

    int leftIndex = left;
    int rightIndex = mid + 1;

    while (leftIndex <= mid && rightIndex <= right) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            temp.push_back(arr[leftIndex++]);
        } else {
            temp.push_back(arr[rightIndex++]);
        }
    }

    while (leftIndex <= mid) {
        temp.push_back(arr[leftIndex++]);
    }

    while (rightIndex <= right) {
        temp.push_back(arr[rightIndex++]);
    }

    for (int i = 0; i < static_cast<int>(temp.size()); i++) {
        arr[left + i] = temp[i];
    }
}


// TODO : Memecah Barisan
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}