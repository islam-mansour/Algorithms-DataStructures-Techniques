#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{

    Queue<int> *Q = new Queue<int>;

    Q->enQueue(1);
    Q->enQueue(2);
    Q->enQueue(3);
    Q->enQueue(4);
    Q->print(); // 1 2 3 4

    Q->deQueue();
    Q->deQueue();
    Q->print(); // 3 4

    return 0;
}
