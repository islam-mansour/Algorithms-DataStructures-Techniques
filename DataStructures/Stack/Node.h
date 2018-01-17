#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T value;
        Node<T>* next;
};

#endif // NODE_H
