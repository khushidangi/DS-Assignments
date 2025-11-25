#include <iostream>
using namespace std;

int heapArr[100];
int heapSize = 0;

void insertPQ(int v) {
    heapArr[heapSize] = v;
    int i = heapSize;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[parent] < heapArr[i]) {
            int t = heapArr[parent];
            heapArr[parent] = heapArr[i];
            heapArr[i] = t;
            i = parent;
        } else break;
    }
    heapSize++;
}

int extractMax() {
    if (heapSize == 0) return -1;
    int maxVal = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heapSize && heapArr[left] > heapArr[largest]) largest = left;
        if (right < heapSize && heapArr[right] > heapArr[largest]) largest = right;
        if (largest != i) {
            int t = heapArr[i];
            heapArr[i] = heapArr[largest];
            heapArr[largest] = t;
            i = largest;
        } else break;
    }
    return maxVal;
}

int main() {
    insertPQ(50);
    insertPQ(20);
    insertPQ(40);
    insertPQ(70);

    cout << extractMax() << endl;
    cout << extractMax() << endl;
    cout << extractMax() << endl;
}
