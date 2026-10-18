#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int stack[100];
    int top = -1;
    int choice, value;

    while (true) {
        cout << "\n1. Place Tray (Push)";
        cout << "\n2. Take Tray (Pop)";
        cout << "\n3. Display Top";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (top == n - 1) {
                cout << "Error: Stack is Full\n";
            } else {
                cout << "Enter tray value: ";
                cin >> value;

                top++;
                stack[top] = value;

                cout << "Top = " << stack[top] << endl;
            }
        }

        else if (choice == 2) {
            if (top == -1) {
                cout << "Error: Stack is Empty\n";
            } else {
                cout << "Taken tray = " << stack[top] << endl;
                top--;
            }
        }

        else if (choice == 3) {
            if (top == -1)
                cout << "Stack is Empty\n";
            else
                cout << "Top = " << stack[top] << endl;
        }

        else if (choice == 4) {
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}