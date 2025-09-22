#include <iostream>
#include <algorithm>
using namespace std;

// Brute Force
int countPairs(int arr[], int size, int k) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

int countPairsTwoPointer(int arr[], int size, int k) {
    sort(arr, arr + size);

    int i = 0, j = 0;
    int cnt = 0;

    while (j < size) {
        if (arr[j] - arr[i] < k) {
            j++;
    } else if (arr[j] - arr[i] > k) {
        i++;
    } else {
        int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;
          
            while(j < size && arr[j] == ele2) {
                j++;
                cnt2++;
            }
          
            while(i < size && arr[i] == ele1) {
                i++;
                cnt1++;
            }
        
            if(ele1 == ele2) {
            	cnt += (cnt1 * (cnt1 - 1))/2;
            } else {
            	cnt += (cnt1 * cnt2);
            }
    }
    return cnt;
}
}

int main() {
    int arr[] = {1, 4, 1, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Brute Force: " << countPairs(arr, size, k) << endl;

    cout << "Better Approach: " << countPairsTwoPointer(arr, size, k) << endl;

    return 0;
}