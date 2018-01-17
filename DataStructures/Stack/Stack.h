#ifndef STACK_H
#define STACK_H

#include "Node.h"

template<class T>
class Stack
{
    private:
        int size;
        Node<T> *top;

    public:
        Stack();
        int getSize();
        Node<T>* getTop();
        void push(T value);
        void pop();
        bool isEmpty();
        void print();
        ~Stack();
};

template<class T>
Stack<T>::Stack(){

    top = new Node<T>;
    size = 0;

}

template<class T>
int Stack<T>::getSize(){
    return size;
}

template<class T>
Node<T>* Stack<T>::getTop(){
    return top;
}

template<class T>
void Stack<T>::push(T value){

    Node<T> *New = new Node<T>;
    New->value = value;

    New->next = top;
    top = New;
    size++;

}

template<class T>
void Stack<T>::pop(){

    Node<T>* tmp = top;
    top = top->next;

    delete tmp;
    size--;

}

template<class T>
bool Stack<T>::isEmpty(){
    return (size == 0);
}

template<class T>
void Stack<T>::print(){

    Node<T>* tmp = top;
    for(int i=0; i<size; ++i){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << '\n';

}

#endif // STACK_H
