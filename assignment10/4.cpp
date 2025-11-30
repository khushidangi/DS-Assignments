#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    const int OFFSET = 100000;
    const int MAX = 200001; // covers range [-100000 .. 100000]

    int freq[MAX] = {0};

    // Step 1: Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i] + OFFSET]++;
    }

    // Step 2: Find first non-repeating element
    for (int i = 0; i < n; i++) {
        if (freq[arr[i] + OFFSET] == 1) {
            cout << arr[i];
            return 0;
        }
    }

    cout << "No non repeating element";
    return 0;
}
