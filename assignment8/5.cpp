#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    heapSortIncreasing(a, n);
    for (int i = 0; i < n / 2; i++) {
        int t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
}

int main() {
    int a[] = {9, 5, 3, 8, 6, 2, 1};
    int n = 7;

    heapSortIncreasing(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int b[] = {9, 5, 3, 8, 6, 2, 1};
    heapSortDecreasing(b, n);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
}
