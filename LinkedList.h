#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAsEveryKthNode(const T &data, int k);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeAllNodes();
    void removeEveryKthNode(int k);

    void swap(Node<T> *node1, Node<T> *node2);
    void shuffle(int seed);

    void print(bool reverse=false) const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;

    int size;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    head = new Node<T>(T(), NULL, NULL);
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    /* TODO */
    head = new Node<T>(T(), NULL, NULL);
    *this = obj;
}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    this->removeAllNodes();
    delete this->head;
}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    return (head->next==NULL) & (head->prev==NULL);
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    int iterator = size+1;
    Node<T> *p = this->getFirstNode();
    while (iterator--){
        if (p==node){
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const {
    /* TODO */
    if (!isEmpty()){
        return head->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
    /* TODO */
    if (!isEmpty()){
        Node<T> *firstNode = this->getFirstNode();
        return firstNode->prev;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    Node<T> *p = this->getFirstNode();
    int iterator = size+1;
    while (!isEmpty() && iterator--){
        if (p->data==data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
    Node<T> *p = this->getFirstNode();

    if (size-1 < index){
        return NULL;
    }
    for (int i=0; i<index; i++){
        p = p->next;
    }
    return p;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */
    if (isEmpty()){
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        head->next = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        size++;
    }
    else {
        Node<T> *firstNode = this->getFirstNode();
        Node<T> *lastNode = this->getLastNode();
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        head->next = newNode;
        newNode->next = firstNode;
        firstNode->prev = newNode;
        newNode->prev = lastNode;
        lastNode->next = newNode;
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    if (isEmpty()){
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        head->next = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        size++;
    }
    else {
        Node<T> *firstNode = this->getFirstNode();
        Node<T> *lastNode = this->getLastNode();
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        newNode->next = firstNode;
        firstNode->prev = newNode;
        newNode->prev = lastNode;
        lastNode->next = newNode;
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node) {
    /* TODO */
    if (isEmpty()){
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        head->next = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        size++;
    }
    else {
        Node<T> *newNode = new Node<T>(data, NULL, NULL);
        Node<T> *afterNode = node->next;

        node->next = newNode;
        newNode->prev = node;
        newNode->next = afterNode;
        afterNode->prev = newNode;

        size++;
    }

}

template<class T>
void LinkedList<T>::insertAsEveryKthNode(const T &data, int k) {
    /* TODO */
    if (k>1){
        for (int i=1; i*k-2<size; i++){
            Node<T> *p = this->getNodeAtIndex(k*i-2);
            this->insertAfterNode(data, p);
        }
    }
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    /* TODO */
    if (this->contains(node)){

        if (size>1){
            Node<T> *prevNode = node->prev;
            Node<T> *nextNode = node->next;

            if(head->next == node){
                head->next = nextNode;
            }

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        else {
            if(head->next == node){
                head->next = NULL;
            }
        }
        delete node;
        size--;
    }

}

template<class T>
void LinkedList<T>::removeNode(const T &data) {
    /* TODO */
    while(this->getNode(data)){
        Node<T>* deleted=this->getNode(data);
        this->removeNode(deleted);
    }
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    /* TODO */
    while(this->getFirstNode()){
        Node<T>* deleted=this->getFirstNode();
        this->removeNode(deleted);
    }
    size=0;
    head->next=NULL;
}

template<class T>
void LinkedList<T>::removeEveryKthNode(int k) {
    /* TODO */
    if (k>1){
        for (int i=1; (k-1)*i<size; i++){
            Node<T> *p = this->getNodeAtIndex((k-1)*i);
            this->removeNode(p);
        }
    }
}

template<class T>
void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) {
    /* TODO */
    if(this->contains(node1)&&this->contains(node2)&&node1!=node2){
        if (node1==this->getFirstNode() && node2==this->getLastNode()){
            node1->prev = node1->next;
            node2->next = node2->prev;

            node1->prev = node2->prev;
            node2->next = node1->next;

            node1->prev->next = node1;
            node2->next->prev = node2;

            node2->prev = node1;
            node1->next = node2;

            head->next = node2;
        }
        else {
            node1->prev->next = node1->next;
            node1->next->prev = node1->prev;
            node1->next=node1->prev;

            node2->prev->next = node2->next;
            node2->next->prev = node2->prev;
            node2->next = node2->prev;

            node1->prev = node2->prev;
            node2->prev = node1->next;

            node1->next = node1->prev;
            node2->next = node2->prev;

            node1->next = node1->next->next;
            node1->next->prev = node1;
            node1->prev->next = node1;

            node2->next = node2->next->next;
            node2->next->prev = node2;      
            node2->prev->next = node2;

            if(head->next==node1){
                head->next = node2;
            }
        }
    }
}

template<class T>
void LinkedList<T>::shuffle(int seed) {
    /* TODO */
    for(int i=0; i<size; i++){
        int index = (i*i+seed)%size;
        Node<int> *node1 = this->getNodeAtIndex(i);
        Node<int> *node2 = this->getNodeAtIndex(index);
        if (i<index){
            this->swap(node1, node2);
        }
        else {
            this->swap(node2, node1);
        }   
    }
}

template<class T>
void LinkedList<T>::print(bool reverse) const {
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (reverse) {
        // traverse in reverse order (last node to first node).

        Node<T> *node = this->getLastNode();

        do {
            std::cout << *node << std::endl;
            node = node->prev;
        }
        while (node != this->getLastNode());
    } else {
        // traverse in normal order (first node to last node).

        Node<T> *node = this->getFirstNode();

        do {
            std::cout << *node << std::endl;
            node = node->next;
        }
        while (node != this->getFirstNode());
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    /* TODO */
    this->removeAllNodes();
    Node<T> *p=rhs.getFirstNode();
    Node<T> *r=rhs.getLastNode();
    // Node<T> *start = new Node<T>(p->data, start, start);

    this->insertAtTheEnd(p->data);

    while(p!=r) {
        p = p->next;
        this->insertAtTheEnd(p->data);
    }
    return *this;
}

#endif //LINKEDLIST_H