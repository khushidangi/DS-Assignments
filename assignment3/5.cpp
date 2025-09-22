#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate_postfix(string postfix) {
    stack<int> operands;

    for (char ch : postfix) {
        if (ch >= '0' && ch <= '9') {
            operands.push(ch - '0');
        } else {
            int right = operands.top(); operands.pop();
            int left = operands.top(); operands.pop();

            switch (ch) {
                case '+': operands.push(left + right); break;
                case '-': operands.push(left - right); break;
                case '*': operands.push(left * right); break;
                case '/': operands.push(left / right); break;
            }
        }
    }

    return operands.top();
}

int main() {
    string postfix_expression;
    cout << "Enter a postfix expression: ";
    cin >> postfix_expression;

    int result = evaluate_postfix(postfix_expression);
    cout << "Result: " << result << endl;

    return 0;
}
