#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.h"

template<class T>
class Double_Linked_List
{
    private:
        Node<T> *Head, *Tail;
        int size;

    public:
        Double_Linked_List();
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
        ~Double_Linked_List();
};

template<class T>
Double_Linked_List<T>::Double_Linked_List(){

    Head = new Node<T>;
    Tail = new Node<T>;
    size = 0;

}

template<class T>
void Double_Linked_List<T>::push(T value){ // O(1)

    if (size == 0){

        Node<T>* New = new Node<T>;
        New->value = value;
        Head = Tail = New;
        size++;
        return;
    }

    Node<T>* New = new Node<T>;
    New->value = value;
    Tail->next = New;
    New->prev = Tail;
    Tail = New;
    size++;

}

template<class T>
void Double_Linked_List<T>::pushFront(T value){ // O(1)

    if (size == 0){

        Node<T>* New = new Node<T>;
        New->value = value;
        Head = Tail = New;
        size++;
        return;
    }

    Node<T>* New = new Node<T>;
    New->value = value;
    Head->prev = New;
    New->next = New;
    Head = New;
    size++;

}

template<class T>
void Double_Linked_List<T>::pop(){ // O(1)

    if(size == 0)
        return;

    Node<T>* tmp = Tail;
    Tail = Tail->prev;
    delete tmp;
    size--;
}

template<class T>
void Double_Linked_List<T>::popFront(){ // O(1)

    if(size == 0)
        return;

    Node<T>* tmp = Head;
    Head = Head->next;
    delete tmp;
    size--;

}

template<class T>
Node<T>* Double_Linked_List<T>::Search(T value){

    Node<T>* tmp = Head;

    for(int i=1; i<size; ++i){

        if(tmp->value == value)
            return tmp;

        tmp = tmp->next;

    }

    return NULL;

}

template<class T>
void Double_Linked_List<T>::insert(int index, T value){

    if(index == 0){
        pushFront(value);
    }

    if(index == size){
        push(value);
    }

    if(index<0 || index>size){
        return;
    }


    Node<T>* New = new Node<T>;
    New->value = value;

    Node<T>* tmp = Head;
    for(int i=0; i<index-1; ++i){
        tmp= tmp->next;
    }

    New->next = tmp->next;
    tmp->next->prev = New;
    New->prev = tmp;
    tmp->next = New;
    size++;

}

template<class T>
void Double_Linked_List<T>::erase(int index){

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

    for(int i=0; i<index; ++i){
        tmp = tmp->next;
    }

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    delete tmp;
    size--;

}

template<class T>
void Double_Linked_List<T>::erase(int start, int end){

    if(start<0 || start>=size || end<0 || end>=size){
        return;
    }

    int n = end - start + 1;

    while(n--){
        this->erase(start);
    }

}

template<class T>
void Double_Linked_List<T>::remove(T value){

    Node<T>* tmp = Head;

    for(int i=0; i<size; ++i){
        if(tmp->value == value){
            this->erase(i);
            return;
        }
        tmp = tmp->next;
    }

}

template<class T>
bool Double_Linked_List<T>::isEmpty(){

    return (size == 0);

}

template<class T>
void Double_Linked_List<T>::print(){

    Node<T>* tmp = Head;

    int n = this->size;

    while(n--){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }

    cout << '\n';

}

template<class T>
Double_Linked_List<T>::~Double_Linked_List(){

    while(!isEmpty()){

        this->pop();

    }

}

#endif // DOUBLE_LINKED_LIST_H
