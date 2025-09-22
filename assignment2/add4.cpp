#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort012(int arr[], int size) {
    int c0 = 0, c1 = 0, c2 = 0;

    for(int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            c0++;
        } else if (arr[i] == 1) {
            c1++;
        } else {
            c2++;
        }
    }

    int index = 0;
    for (int i = 0; i < c0; i++) {
        arr[index++] = 0;
    }
    for (int i = 0; i < c1; i++) {
        arr[index++] = 1;
    }
    for (int i = 0; i < c2; i++) {
        arr[index++] = 2;
    }
}

// Better Approach
void sortMid(int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high--]);
        }
    }
}

int main() {
    int arr[] = {0, 1, 2, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortMid(arr, size);

    printArr(arr, size);

    return 0;
}