#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{

    Stack<int> *S = new Stack<int>;

    S->push(1);
    S->push(2);
    S->push(3);
    S->push(4);
    S->print(); // 4 3 2 1

    S->pop();
    S->pop();
    S->print(); // 2 1

    return 0;
}
