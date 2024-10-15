#pragma once

template <class T>
struct Node {
    T info;
    Node* next;
};

template <class T>
class linkedList {
protected:
    Node<T>* head;
public:
    linkedList();
    ~linkedList();
    bool isEmpty() const;
    Node<T>* getHead() const;

    void setHead(Node<T>* newHead) { head = newHead; }
};

template <class T>
linkedList<T>::linkedList() : head(nullptr) {}

template <class T>
linkedList<T>::~linkedList() {
    Node<T>* current = head;
}

template <class T>
bool linkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
Node<T>* linkedList<T>::getHead() const {
    return head;
}
