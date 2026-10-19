#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int table[SIZE];

    // Initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle registration numbers:\n";

    for (int i = 0; i < n; i++)
    {
        int reg;
        cin >> reg;

        int index = reg % SIZE;
        int start = index;

        // Find empty slot
        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;

            // Table is full
            if (index == start)
            {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (table[index] == -1)
            table[index] = reg;
    }

    cout << "\nFinal Parking Lot:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}