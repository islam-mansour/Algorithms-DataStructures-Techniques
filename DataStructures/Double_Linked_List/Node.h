#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:

        T value;
        Node<T> *next, *prev;

        Node();


};

template<class T>
Node<T>::Node(){

    next = prev = NULL;

}

#endif // NODE_H
