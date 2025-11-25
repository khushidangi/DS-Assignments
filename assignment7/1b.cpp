#include <iostream>
using namespace std;

const int MAX = 100;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int original[] = {64, 25, 12, 22, 11};
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX], arr5[MAX];
    copy(original, original + n, arr1);
    copy(original, original + n, arr2);
    copy(original, original + n, arr3);
    copy(original, original + n, arr4);
    copy(original, original + n, arr5);

    insertionSort(arr1, n);
    cout << "Insertion Sort: "; printArray(arr1, n);
    return 0;
}