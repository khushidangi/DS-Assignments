#include <iostream>
using namespace std;

const int MAX = 100;

void printArray(int arr[], int size, const string title) {
    cout << title << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int countUniqueElements(int arr[], int res[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < count; j++) {
            if (arr[i] == res[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            res[count] = arr[i];
            count++;
        }
    }
    cout << "Number of unique elements: " << count << endl;
    return count;
}

void reduceSize(int &size, int count) {
    size = size - count;
}

int main() {
    int arr[MAX] = {1, 1, 3, 5, 7, 5};
    int size = 6;

    printArray(arr, size, "Original Array");
    cout << endl;

    int res[MAX];
    int uniqueCount = countUniqueElements(arr, res, size);
    cout << endl;
    printArray(res, uniqueCount, "Unique Elements");

    return 0;
}