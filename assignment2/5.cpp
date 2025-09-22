#include <iostream>
using namespace std;


void enterValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printDiagonal(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                cout << arr[i] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void printTriDiagonal(int arr[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i - j) > 1 || (j - i) > 1) {
                cout << 0 << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}

void lowerTriangular(int arr[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < j) {
                cout << 0 << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}

void upperTriangular(int arr[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i > j) {
                cout << 0 << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}

void symmetricMatrix (int arr[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                cout << arr[i] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    const int size = 10;
    int arr[size];

    enterValues(arr, size);


    return 0;
}