
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            }
        }

        // Operator
        else {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;

    return 0;
}
