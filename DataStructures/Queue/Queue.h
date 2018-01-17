#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template<class T>
class Queue
{
    private:
        int size;
        Node<T> *Front, *Rear;

    public:
        Queue();
        int getSize();
        Node<T>* getFront();
        Node<T>* getRear();
        void enQueue(T value);
        void deQueue();
        bool isEmpty();
        void print();
        ~Queue();
};

template<class T>
Queue<T>::Queue(){
    Front = new Node<T>;
    Rear = new Node<T>;
    size = 0;
}

template<class T>
int Queue<T>::getSize(){
    return size;
}

template<class T>
Node<T>* Queue<T>::getFront(){
    return Front;
}

template<class T>
Node<T>* Queue<T>::getRear(){
    return Rear;
}

template<class T>
void Queue<T>::enQueue(T value){

    Node<T>* New = new Node<T>;
    New->value = value;

    if(size == 0){
        Front = Rear = New;
        size++;
        return;
    }

    Rear->next = New;
    Rear = New;
    size++;
}


template<class T>
void Queue<T>::deQueue(){

    Node<T>* tmp = Front;
    Front = Front->next;

    delete tmp;
    size--;

}

template<class T>
bool Queue<T>::isEmpty(){
    return (size == 0);
}


template<class T>
void Queue<T>::print(){

    Node<T> *tmp = Front;
    for(int i=0; i<size; ++i){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << '\n';

}

#endif // QUEUE_H
