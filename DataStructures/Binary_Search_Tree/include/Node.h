#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T value;
        Node<T> *left, *right, *parent;
        Node();

};

template<class T>
Node<T>::Node(){

    left = right = parent = NULL;

}

#endif // NODE_H
