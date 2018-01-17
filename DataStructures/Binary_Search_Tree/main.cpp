#include <iostream>
#include "BST.h"
using namespace std;

int main()
{

    BST<int>* bst = new BST<int>;
    bst->add(4);
    bst->add(2);
    bst->add(6);
    bst->add(1);
    bst->add(3);
    bst->add(5);
    bst->add(7);
    bst->printInOrder(bst->getRoot()); // 1 2 3 4 5 6 7
    cout << endl;
    bst->printPreOrder(bst->getRoot()); // 4 2 1 3 6 5 7
    cout << endl;
    bst->printPostOrder(bst->getRoot()); // 1 3 2 5 7 6 4
    cout << endl;


    return 0;
}
