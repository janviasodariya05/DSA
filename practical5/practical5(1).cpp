#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void addFirst(string s) {
    Node* newNode = new Node(s);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addLast(string s) {
    Node* newNode = new Node(s);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAfter(string given, string s) {
    Node* temp = head;

    while (temp != NULL && temp->song != given)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Song not found\n";
        return;
    }

    Node* newNode = new Node(s);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void removeFirst() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
}

int countSongs() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << "\nCount = " << countSongs() << endl;
}

int main() {
    addFirst("A");
    display();

    addLast("B");
    display();

    addLast("C");
    display();

    insertAfter("B", "X");
    display();

    removeFirst();
    display();

    return 0;
}