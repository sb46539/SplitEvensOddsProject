#pragma once
#include "LinkedList.h"

template <class T>
class unorderedLinkedList : public linkedList<T> {
public:
    void insert(const T& newItem);
};

template <class T>
void unorderedLinkedList<T>::insert(const T& newItem) {
    Node<T>* newNode = new Node<T>{ newItem, nullptr };
    if (this->head == nullptr) {
        this->setHead(newNode);
    }
    else {
        Node<T>* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
