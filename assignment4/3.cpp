#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n;

    cout << "Enter number of elements in the queue: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int half = n / 2;
    int result[100];
    int index = 0;

    int i = 0;
    int j = half;

    while (i < half && j < n) {
        result[index++] = arr[i++];
        result[index++] = arr[j++];
    }

    while (i < half) {
        result[index++] = arr[i++];
    }

    while (j < n) {
        result[index++] = arr[j++];
    }

    cout << "Interleaved queue: ";
    for (int k = 0; k < n; k++) {
        cout << result[k] << " ";
    }
    cout << endl;

    return 0;
}
