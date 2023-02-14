#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void showArray(int arr[], int size){
    cout << " [";
    for(int i = 0; i < size-1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[size-1] << "] " << endl;
}

void merge(int arr[], int left, int mid, int right){
    int k; // untuk menentukan key
    int n1 = mid - left + 1; // untuk menentukan jumlah data sebelah kiri
    int n2 = right - mid; // untuk menentukan jumlah data sebelah kanan

    // temporary array untuk menyimpan data yang akan digabungkan
    int L[n1]; // untuk data sebelah kiri
    int R[n2]; // untuk data sebelah kanan

    // mengcopykan data yang akan digabungkan ke dalam temporary array
    // untuk sebelah kiri
    for(int i = 0; i < n1; i++){
        L[i] = arr[left+i];
    }
    // untuk sebelah kanan
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid+1+j];
    }

    // proses penggabungan
    int i = 0; // kita reset variable i dan j nya
    int j = 0;
    k = left; // key yang pertama kita taruh ke bagian yang paling kiri

    // untuk menghabiskan data
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){ // jika lebih kecil yang kiri
            arr[k] = L[i];
            i++;
        }else{ // jika lebih besar yang kanan
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // jika elemen di salah satu sisi sudah habis
    // tapi di sisi lain masih belum habis
    while(i < n1){ // kalau yang dibagian kiri belum habis kita masukkan semua data yang dibagian kiri ke dalam array
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){ // kalau yang dibagian kanan belum habis kita masukkan semua data yang dibagian kanan ke dalam array
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){ // kondisi rekuren
        int mid = left + (right - left) / 2; // mencari nilai tengah untuk menentukan bagian kiri dan kanan

        mergeSort(arr, left, mid); // bagian kiri
        mergeSort(arr, mid+1, right); // bagian kanan

        merge(arr, left, mid, right); // hasil penggabungan
    }
}

int main(){
    int size;
    
    cout << "\n============================================" << endl;
    cout << "          PROGRAM MERGE SHORTING          " << endl;
    cout << "============================================" << endl;
    cout << "\nMasukan Banyak Data\t: "; cin >> size;

    int arr[size];
    
    for (int i = 0; i < size; ++i){
        cout << "\nMasukan Data ke-"<< i + 1 <<"\t: ";
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n============================================" << endl;
    cout << "Data sebelum diurutkan : ";
    showArray(arr, n);

    mergeSort(arr, 0, n-1);
    cout << "\nData setelah diurutkan : ";
    showArray(arr, n);
    cout << "============================================" << endl;

    return 0;
}
