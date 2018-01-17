#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include "Node.h"


template<class T>
class Linked_List
{
    private:
        Node<T> *Head, *Tail;
        int size;

    public:
        Linked_List();
        void push(T value); // add at the end
        void pushFront(T value); // add at the front
        void pop(); // remove from the end
        void popFront(); // remove from the front
        Node<T>* Search(T key); // return the node that contains the key
        void insert(int index, T value); // add in a certain index
        void erase(int index); // remove a certain index
        void erase(int start, int end); // remove all elements from 'start' to 'end'
        void remove(T value); // remove all Nodes that its value is equal to 'value'
        bool isEmpty(); // return true if list is empty, false otherwise
        void print(); // print the list
        ~Linked_List();

};


template <class T>
Linked_List<T>::Linked_List(){
    Head = new Node<T>();
    Tail = new Node<T>();
    size = 0;
}

template <class T>
void Linked_List<T>::push(T value){ // O(1)

    if(size == 0){
        Node<T>* New = new Node<T>;
        New->value = value;
        Head = Tail = New;
        size++;
        return;
    }

    Node<T>* New = new Node<T>;
    New->value = value;
    Tail->next = New;
    Tail = New;
    ++size;
}

template<class T>
void Linked_List<T>::pushFront(T value){ // O(1)

    if(size == 0){
        Node<T>* New = new Node<T>;
        New->value = value;
        Head = Tail = New;
        size++;
        return;
    }

    Node<T>* New;
    New->value = value;
    New->next = Head;
    Head = New;
    ++size;

}

template <class T>
void Linked_List<T>::pop(){ // O(n)

    if(size == 0)
        return;

    delete Tail;
    --size;

    Tail = Head;
    for(int i=1; i<size; ++i){
        Tail = Tail->next;
    }
}

template<class T>
void Linked_List<T>::popFront(){ // O(1)

    if(size == 0)
        return;

    Node<T>* tmp = Head;
    Head = Head->next;
    delete tmp;
    --size;

}

template <class T>
Node<T>* Linked_List<T>::Search(T key){ // O(n)

    Node<T>* tmp = Head;

    for(int i=0; i<size; ++i){
        if(tmp->value == key)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;

}

template <class T>
void Linked_List<T>::insert(int index, T value){ // O(n)


    if(index == 0){
        pushFront(value);
        return;
    }
    if(index == size){
        push(value);
        return;
    }

    if(index<0 || index>size){ // index out of range
        return;
    }

    Node<T>* New = new Node<T>();
    New->value = value;

    Node<T>* tmp = Head;

    for(int i=1;i<index; ++i){
        tmp = tmp->next;
    }

    New->next = tmp->next;
    tmp->next = New;
    ++size;
}

template <class T>
void Linked_List<T>::erase(int index){ // O(n)

    if(index == 0){
        popFront();
        return;
    }

    if(index == size-1){
        pop();
        return;
    }

    if(index<0 || index>=size){
        return;
    }

    Node<T>* tmp = Head;

    for(int i=1;i<index; ++i){
        tmp = tmp->next;
    }

    Node<T>* target = tmp->next;
    tmp->next = target->next;

    delete tmp;
    size--;

}

template <class T>
void Linked_List<T>::erase(int start, int end){ // O(n)

    if(start<0 || start>=size || end<0 || end>=size){
        return;
    }

    int n = end - start + 1;

    while(n--){
        this->erase(start);
    }

}

template <class T>
void Linked_List<T>::remove(T value){ // O(n)

    Node<T>* tmp = Head;

    for(int i=0; i<size; ++i){
        if(tmp->value == value){
            this->erase(i);
            return;
        }
        tmp= tmp->next;
    }

}

template <class T>
bool Linked_List<T>::isEmpty(){ // O(1)

    return (size == 0);

}

template <class T>
void Linked_List<T>::print(){ // O(n)

    Node<T>* tmp = Head;

    int n = this->size;

    while(n--){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }

    cout << '\n';

}

template <class T>
Linked_List<T>::~Linked_List(){ // O(n)

    while(!isEmpty()){

        this->pop();

    }

}


#endif // LINKED_LIST_H
