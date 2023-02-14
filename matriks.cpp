#include <iostream>

using namespace std;

int main(){
    int A[3][3], P[3][3];
    double determinan;

    cout << "SELAMAT DATANG DI PROGRAM INVERS MATRIKS 3x3\n" << endl;

    // INPUT ELEMEN MATRIKS A
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "baris: " << i+1 << ", kolom: " << j+1 << " : "; cin >> A[i][j];
        }
    }

    // OUTPUT ELEMEN MATRIKS A
    cout << endl;
    cout << "Matriks A: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // PROSES MENENTUKAN DETERMINAN MATRIKS A
    determinan = A[0][0]*A[1][1]*A[2][2] + // [1,1]*[2,2]*[3,3]
                 A[0][1]*A[1][2]*A[2][0] + // [1,2]*[2,3]*[3,1]
                 A[0][2]*A[1][0]*A[2][1] - // [1,3]*[2,1]*[3,2]
                 A[0][2]*A[1][1]*A[2][0] - // [1,3]*[2,2]*[3,1]
                 A[0][0]*A[1][2]*A[2][1] - // [1,1]*[2,3]*[3,2]
                 A[0][1]*A[1][0]*A[2][2];  // [1,2]*[2,1]*[3,3]
    cout << endl;
    cout << "Determinan matrriks A = " << determinan << endl;

    P[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
    P[0][1] = A[1][0] * A[2][2] - A[1][2] * A[2][0];
    P[0][2] = A[1][0] * A[2][1] - A[1][2] * A[2][0];
    P[1][0] = A[0][1] * A[2][2] - A[0][2] * A[2][1];
    P[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
    P[1][2] = A[0][0] * A[2][1] - A[0][1] * A[2][0];
    P[2][0] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
    P[2][1] = A[0][0] * A[1][2] - A[0][2] * A[1][0];
    P[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    if(determinan != 0){
        // Minor Matriks A
        cout << "\n\nMinor Matriks A: " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << P[i][j] << "\t";
            }
            cout << endl;
        }

        P[0][0] = P[0][0]; // baris 1 kolom 1
        P[0][1] = -1*(P[0][1]); // baris 1 kolom 2
        P[0][2] = P[0][2]; // baris 1 kolom 3
        P[1][0] = -1*(P[1][0]); // baris 2 kolom 1
        P[1][1] = P[1][1]; // baris 2 kolom 2
        P[1][2] = -1*(P[1][2]); // baris 2 kolom 3
        P[2][0] = P[2][0]; // baris 3 kolom 1
        P[2][1] = -1*(P[2][1]); // baris 3 kolom 2
        P[2][2] = P[2][2]; // baris 3 kolom 3

        // Kofaktor Matriks A
        cout << "\n\nKofaktor Matriks A: " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << P[i][j] << "\t";
            }
            cout << endl;
        }

        // Adjoin Matriks A
        cout << "\n\nAdjoin Matriks A: " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << P[j][i] << "\t";
            }
            cout << endl;
        }

        // Invers Matriks A
        cout << "\n\nInvers Matriks A: " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << 1/determinan * P[j][i] << "\t";
            }
            cout << endl;
        }
    }else{
        cout << "\nMatriks tersebut tidak memiliki invers, dikarenakan determinan matriks tersebut bernilai 0" << endl;
    }

    return 0;
}








