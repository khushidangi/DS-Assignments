#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool compare(char a, char b) {
        return (a == '(' && b == ')') ||
               (a == '{' && b == '}') ||
               (a == '[' && b == ']');
    }

    bool isValid(string s) {
        stack<char> st;
        int size = s.size();
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                if(!compare(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s = "{[]()}";
    if (solution.isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}