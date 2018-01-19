#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T value;
        Node<T> *parent, *left, *right;

        Node();
};

template<class T>
Node<T>::Node(){

    parent = left = right = NULL;

}

#endif // NODE_H
