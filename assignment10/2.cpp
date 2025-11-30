#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int A[1000];
    for(int i=0;i<n;i++) cin >> A[i];

    cin >> m;
    int B[1000];
    for(int i=0;i<m;i++) cin >> B[i];

    int freq[10000];
    for(int i=0;i<10000;i++) freq[i] = 0;

    for(int i=0;i<n;i++) freq[A[i]] = 1;

    for(int i=0;i<m;i++) {
        if(freq[B[i]] == 1) {
            cout << B[i] << " ";
        }
    }
}
