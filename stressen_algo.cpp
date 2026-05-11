#include <iostream>
using namespace std;

#define max 64

void add(int A[max][max], int B[max][max], int C[max][max], int size) {
    for (int i=0; i<size;i++) {
        for (int j=0; j<size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[max][max], int B[max][max], int C[max][max], int size) {
    for (int i=0; i<size;i++) {
        for (int j=0; j<size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void stressen(int A[max][max], int B[max][max], int C[max][max], int size) {
    if (size==1) {
        C[0][0] = A[0][0]*B[0][0];
        return;
    }

    int newSize = size/2;


    //Define the matrices
    int A11[max][max], A12[max][max], A21[max][max], A22[max][max];
    int B11[max][max], B12[max][max], B21[max][max], B22[max][max];

    //Fill the matrices
    for (int i=0; i<newSize; i++) {
        for (int j =0; j<newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+newSize];
            A21[i][j] = A[i+newSize][j];
            A22[i][j] = A[i+newSize][j+newSize];


            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+newSize];
            B21[i][j] = B[i+newSize][j];
            B22[i][j] = B[i+newSize][j+newSize];
        }
    }



    int P1[max][max], P2[max][max], P3[max][max], P4[max][max], P5[max][max], P6[max][max], P7[max][max];
    int C11[max][max], C12[max][max], C21[max][max], C22[max][max];

    int temp1[max][max], temp2[max][max];



    //P1: A11 S1
    subtract(B12, B22, temp1, newSize);
    stressen(A11, temp1, P1, newSize);

    //P2: S2 B22
    add(A11, A12, temp1, newSize);
    stressen(temp1, B22, P2, newSize);

    //P3: S3 B11
    add(A21, A22, temp1, newSize);
    stressen(temp1, B11, P3, newSize);

    //P4: A22 S4
    subtract(B21, B11, temp1, newSize);
    stressen(A22, temp1, P4, newSize);


    //P5: S5 S6
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    stressen(temp1, temp2, P5, newSize);


    //P6: S7 S8
    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    stressen(temp1, temp2, P6, newSize);

    //P7: S9 S10
    subtract(A11, A21, temp1, newSize);
    add(B11, B12, temp2, newSize);
    stressen(temp1, temp2, P7, newSize);



    //C11 : P5+P4-P2+P6
    add(P5, P4, temp1, newSize);
    subtract(temp1, P2, temp2, newSize);
    add(temp2, P6, C11, newSize);

    //C12 : P1+P2
    add(P1, P2, C12, newSize);

    //C21 : P3+P4
    add(P3, P4, C21, newSize);

    //C22 : P5+P1-P3-P7
    add(P5, P1, temp1, newSize);
    subtract(temp1, P3, temp2, newSize);
    subtract(temp2, P7, C22, newSize);

    for (int i=0; i<newSize; i++) {
        for (int j=0; j<newSize; j++) {

            C[i][j] = C11[i][j];
            C[i][j+newSize] = C12[i][j];
            C[i+newSize][j] = C21[i][j];
            C[i+newSize][j+newSize] = C22[i][j];

        }
    }
    
}

int main() {
    int size = 4; 
    int A[max][max] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13, 14, 15, 16}};
    int B[max][max] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13, 14, 15, 16}};
    int C[max][max];

    stressen(A, B, C, size);

    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}