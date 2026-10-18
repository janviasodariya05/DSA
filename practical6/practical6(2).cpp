#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

// Visit a new page
void visit(string page) {
    Node* n = new Node;
    n->page = page;
    n->next = top;
    top = n;

    cout << "Current Page: " << top->page << endl;
}

// Back
void back() {
    if (top == NULL) {
        cout << "No history left\n";
        return;
    }

    Node* temp = top;
    top = top->next;

    delete temp;

    if (top != NULL)
        cout << "Current Page: " << top->page << endl;
    else
        cout << "No page left\n";
}

int main() {
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            visit(page);
        }
        else if (choice == 2) {
            back();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}