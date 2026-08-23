#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> q;

    q.push_front(10);

    cout << "After critical: ";

    list<int>::iterator i;

    for (i = q.begin(); i != q.end(); i++)
        cout << *i << " ";

    cout << endl;


    q.push_back(20);

    cout << "After routine: ";

    for (i = q.begin(); i != q.end(); i++)
        cout << *i << " ";

    cout << endl;

    
    int patient = 30;
    int position = 1;

    if (position <= q.size())
    {
        i = q.begin();

        for (int j = 0; j < position; j++)
            i++;

        q.insert(i, patient);
    }
    else
    {
        
        q.push_back(patient);
    }

    cout << "Final queue: ";

    for (i = q.begin(); i != q.end(); i++)
        cout << *i << " ";

    return 0;
}