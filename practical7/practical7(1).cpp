#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token) {
        if (count == MAX) {
            cout << "Error: Queue is full\n";
            return;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Served token: " << arr[front] << endl;
        front = (front + 1) % MAX;
        count--;

        if (count > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Queue is empty\n";
    }
};

int main() {
    Queue q;

    q.join(101);
    q.join(102);
    q.join(103);
    q.serve();
    q.join(104);
    q.join(105);
    q.join(106);
    q.serve();

    return 0;
}