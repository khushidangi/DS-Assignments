#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    int count[256] = {0};
    int n = str.length();
    char queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        count[(int)ch]++;
        queue[rear++] = ch;

        while (front < rear && count[(int)queue[front]] > 1) {
            front++;
        }

        if (front < rear) {
            cout << queue[front] << " ";
        } else {
            cout << -1 << " ";
        }
    }

    cout << endl;
    return 0;
}
