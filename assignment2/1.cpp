#include <iostream>
using namespace std;

const int MAX = 100;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            cout << "Element " << target << " found at index: " << mid << endl;
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "Element " << target << " not found in the array." << endl;
    return -1;
}

void insertElement(int arr[], int size, int value) {
    int i = size - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = value;
    size++;
}

int main() {
    int arr[MAX] = {1, 2, 3, 5, 6, 7};
    int size = 6;

    int target = 4;
    cout << "\nInserting " << target << " into the array." << endl;
    insertElement(arr, size, target);

    cout << "Array after insertion: ";
    printArray(arr, size);

    cout << "\nSearching for " << target << " in the new array." << endl;
    binarySearch(arr, size, target);
}