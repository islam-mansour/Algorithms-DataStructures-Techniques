#ifndef BST_H
#define BST_H

#include "Node.h"

template<class T>
class BST
{
    private:
        int size;
        Node<T>* root;

    public:
        BST();
        Node<T>* getRoot();
        int getSize();
        Node<T>* Search(T value); // search for a value
        void add(T value); // add new node in the tree
        void remove(T value); // remove node from tree
        Node<T>* getSuccessor(Node<T>* current); // return the successor of a node
        Node<T>* getPredecessor(Node<T>* current); // return the predecessor node
        void printInOrder(Node<T>* tmp); // traverse and print the tree using in order
        void printPostOrder(Node<T>* tmp); // traverse and print the tree using post order
        void printPreOrder(Node<T>* tmp); // traverse and print the tree using pre order
        ~BST();

};

template<class T>
BST<T>::BST(){
    root = new Node<T>;
    root = NULL;
    size = 0;
}

template<class T>
Node<T>* BST<T>::getRoot(){
    return root;
}

template<class T>
int BST<T>::getSize(){
    return size;
}

template<class T>
Node<T>* BST<T>::Search(T value){ // O( log(n) )

    Node<T>* tmp = root;

    while(tmp != NULL){

        if(tmp->value == value){
            return tmp;
        }

        if(tmp->value < value){
            tmp = tmp->right;
        }
        else{
            tmp = tmp->left;
        }

    }

    return NULL;

}

template<class T>
void BST<T>::add(T value){ // O( log(n) )

    if(this->Search(value) != NULL){
        return;
    }

    Node<T>* New = new Node<T>();
    New->value = value;

    if(root == NULL){
        root = New;
        size++;
        return;
    }

    Node<T>* tmp = root;
    while(true){

        if(tmp->value < value){
            if(tmp->right == NULL){
                tmp->right = New;
                size++;
                return;
            }
            tmp = tmp->right;
        }
        else{
            if(tmp->left == NULL){
                tmp->left = New;
                size++;
                return;
            }
            tmp = tmp->left;
        }

    }

}

template<class T>
void BST<T>::remove(T value){ // O( log(n) )

    if(this->Search(value) == NULL){
        return;
    }

    Node<T>* tmp = root;
    while(tmp != NULL){

        if(tmp->value == value){

            if(this->getSuccessor(tmp) != NULL){

                if(tmp->parent->value < tmp->value){
                    tmp->parent->right = getSuccessor(tmp);
                }
                else{
                    tmp->parent->left = getSuccessor(tmp);
                }

            }

            else if (this->getPredecessor(tmp) != NULL){

                if(tmp->parent->value < tmp->value){
                    tmp->parent->right = getPredecessor(tmp);
                }
                else{
                    tmp->parent->left = getPredecessor(tmp);
                }

            }

            delete tmp;
            size--;

        }

        if(tmp->value < value){
            tmp = tmp->right;
        }
        else{
            tmp = tmp->left;
        }


    }

}

template<class T>
Node<T>* BST<T>::getSuccessor(Node<T>* current){ // O(n)
    return current->right;
}

template<class T>
Node<T>* BST<T>::getPredecessor(Node<T>* current){ // O(n)
    return current->left;
}


template<class T>
void BST<T>::printInOrder(Node<T>* tmp){ // O(n)
    if(tmp == NULL)
        return;

    printInOrder(tmp->left);
    cout << tmp->value << " ";
    printInOrder(tmp->right);

}

template<class T>
void BST<T>::printPostOrder(Node<T>* tmp){
    if(tmp == NULL)
        return;

    printPostOrder(tmp->left);
    printPostOrder(tmp->right);
    cout << tmp->value << " ";

}

template<class T>
void BST<T>::printPreOrder(Node<T>* tmp){
    if(tmp == NULL)
        return;

    cout << tmp->value << " ";
    printPreOrder(tmp->left);
    printPreOrder(tmp->right);

}


#endif // BST_H
