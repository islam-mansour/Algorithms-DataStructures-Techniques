#include <iostream>
#include "Max_Heap.h"
using namespace std;

int main()
{

    Max_Heap<double> *MH = new Max_Heap<double>();

    MH->add(1.0);
    MH->add(1.1);
    MH->add(1.2);
    MH->add(1.3);

    cout << MH->getMax() << endl;
    MH->removeRoot();

    cout << MH->getMax() << endl;
    MH->removeRoot();

    cout << MH->getMax() << endl;
    MH->removeRoot();

    cout << MH->getMax() << endl;
    MH->removeRoot();

    delete MH;

    return 0;
}
