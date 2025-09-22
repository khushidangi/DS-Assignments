#include <iostream>
#include <stack>
using namespace std;

void pushString(stack<string>& s, const string& str) {
    s.push(str);
}

void popReverseString(stack<string>& s) {
    while (!s.empty()) {
        string str = s.top();
        s.pop();
        for (int i = str.length() - 1; i >= 0; --i) {
            cout << str[i];
        }
    }
}

int main() {
    stack<string> stack;
    string str = "DataStructure";

    pushString(stack, str);
    popReverseString(stack);

    return 0;
}