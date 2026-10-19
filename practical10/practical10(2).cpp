
#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

int main()
{
    vector<int> table[SIZE];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> code;
        int index = code % SIZE;
        table[index].push_back(code);
    }

    cout << "\nFinal Shelves:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Shelf " << i << ": ";

        if (table[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (vector<int>::size_type j = 0;
                 j < table[i].size(); j++)
            {
                cout << table[i][j] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
