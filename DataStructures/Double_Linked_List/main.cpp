#include <iostream>
#include "Double_Linked_List.h"
using namespace std;

int main()
{

    Double_Linked_List<int>* ll = new Double_Linked_List<int>;

    ll->push(1);
    ll->push(3);
    ll->push(4);
    ll->push(5);
    ll->push(6);
    ll->print(); // 1 3 4 5 6

    ll->pop();
    ll->print(); // 1 3 4 5

    ll->insert(1,2); // 1 2 3 4 5
    ll->print();

    ll->erase(0); // 2 3 4 5
    ll->print();

    ll->erase(0,1); // 4 5
    ll->print();

    cout << (ll->Search(4) != NULL ? "found\n" : "not found\n"); // found

    delete ll;

    return 0;
}
