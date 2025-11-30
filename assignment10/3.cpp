#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for(int i=0;i<n;i++) cin >> a[i];

    int freq[10000];
    for(int i=0;i<10000;i++) freq[i] = 0;

    for(int i=0;i<n;i++) {
        freq[a[i]]++;
    }

    for(int i=0;i<10000;i++) {
        if(freq[i] > 0) {
            cout << i << " -> " << freq[i] << " times" << endl;
        }
    }

    return 0;
}
