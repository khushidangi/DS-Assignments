#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool flag;
    for (int i = 1; i < size; i++) {
        flag = true;
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == true) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}