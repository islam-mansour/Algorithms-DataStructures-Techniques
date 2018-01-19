#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Node.h"
#include <vector>

template<class T>
class Max_Heap
{
    private:
        Node<T> *root;
        int size;

        Node<T>* getFirstAvail();
        Node<T>* heapify(Node<T>*);
        Node<T>* makeLeaf(Node<T>*);
        void swap(Node<T>*, Node<T>*);

    public:
        Max_Heap();

        void add(T value); // add new node to the tree
        T getMax(); // get Max element in the tree (the root)
        void removeRoot(); // delete the root
        Node<T>* getRoot(); // return root
        int getSize(); // return number of nodes

        ~Max_Heap();
};

template<class T>
Max_Heap<T>::Max_Heap(){
    root = new Node<T>;
    root = NULL;
    size = 0;
}


template<class T>
void Max_Heap<T>::swap(Node<T>* n1, Node<T>* n2){
    T tmpValue = n1->value;
    n1->value = n2->value;
    n2->value = tmpValue;
}


template<class T>
Node<T>* Max_Heap<T>::getFirstAvail(){

    vector< Node<T>* > *V = new vector< Node<T>* >();
    V->push_back(root);

    while(V->size()){

        Node<T> *tmp = V->front();
        V->erase(V->begin());

        if(tmp->left==NULL || tmp->right==NULL){
            delete V;
            return tmp;
        }

        V->push_back(tmp->left);
        V->push_back(tmp->right);

    }

}


template<class T>
Node<T>* Max_Heap<T>::makeLeaf(Node<T>* tmp){

    if(tmp->left == NULL && tmp->right == NULL)
        return tmp;

    else if (tmp->left != NULL && tmp->right == NULL){
        swap(tmp, tmp->left);
        return makeLeaf(tmp->left);
    }

    else if (tmp->left == NULL && tmp->right != NULL){
        swap(tmp, tmp->right);
        return makeLeaf(tmp->right);
    }

    else {
        if (tmp->left->value > tmp->right->value){
            swap(tmp, tmp->left);
            return makeLeaf(tmp->left);
        }
        else {
            swap(tmp, tmp->right);
            return makeLeaf(tmp->right);
        }
    }

}

template<class T>
Node<T>* Max_Heap<T>::heapify(Node<T>* New){

    Node<T>* tmp = New;

    while(tmp->parent != NULL){

        if(tmp->parent->value < tmp->value){

            swap(tmp, tmp->parent);

            tmp = tmp->parent;

        }
        else{
            break;
        }

    }

}

template<class T>
Node<T>* Max_Heap<T>::getRoot(){
    return root;
}

template<class T>
int Max_Heap<T>::getSize(){
    return size;
}

template<class T>
void Max_Heap<T>::add(T value){

    Node<T> *New = new Node<T>();
    New->value = value;

    size++;

    if(root == NULL){
        root = New;
        return;

    }

    Node<T>* tmp = this->getFirstAvail();

    if(tmp->left == NULL)
        tmp->left = New;
    else
        tmp->right = New;

    New->parent = tmp;

    New = heapify(New);


}

template<class T>
T Max_Heap<T>::getMax(){
    return root->value;
}

template<class T>
void Max_Heap<T>::removeRoot(){

    if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL;
    }

    else {

        Node<T>* tmp = makeLeaf(root);

        if(tmp->parent->left == tmp){
            tmp->parent->left = NULL;
        } else {
            tmp->parent->right = NULL;
        }

        delete tmp;

    }

    size--;

}

template<class T>
Max_Heap<T>::~Max_Heap(){

    while(size){
        removeRoot();
    }

}

#endif // MAX_HEAP_H
