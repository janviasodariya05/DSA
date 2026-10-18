#include <iostream>
#include <queue>
using namespace std;

class PatientQueue {
    queue<string> patients;

public:
    void arrive(string name) {
        patients.push(name);

        cout << "Front patient: " << patients.front() << endl;
    }

    void attend() {
        if (patients.empty()) {
            cout << "Error: No patients waiting\n";
            return;
        }

        cout << "Attended patient: " << patients.front() << endl;
        patients.pop();

        if (!patients.empty())
            cout << "Front patient: " << patients.front() << endl;
        else
            cout << "Ward is empty\n";
    }
};

int main() {
    PatientQueue q;

    q.arrive("Patient A");
    q.arrive("Patient B");
    q.arrive("Patient C");

    q.attend();
    q.attend();

    q.arrive("Patient D");

    q.attend();
    q.attend();
    q.attend();

    return 0;
}