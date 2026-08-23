#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> q;

    
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);

    list<int>::iterator i;

    
    cout << "Queue from front to back: ";

    for (i = q.begin(); i != q.end(); i++)
        cout << *i << " ";

    cout << endl;

    
    q.remove(30);

    cout << "After deleting 30: ";

    for (i = q.begin(); i != q.end(); i++)
        cout << *i << " ";

    cout << endl;

    
    cout << "Queue from last to first: ";

    list<int>::reverse_iterator r;

    for (r = q.rbegin(); r != q.rend(); r++)
        cout << *r << " ";

    cout << endl;

    return 0;
}