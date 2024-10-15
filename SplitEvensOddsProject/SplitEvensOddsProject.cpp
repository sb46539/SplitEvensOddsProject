#include <iostream>
#include "IntLinkedList.h"

using namespace std;

void displayEvensOdds(const intLinkedList& evensList, const intLinkedList& oddsList) {
    cout << "Evens list: ";
    Node<int>* current = evensList.getHead();
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Odds list: ";
    current = oddsList.getHead();
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    intLinkedList originalList;
    intLinkedList evensList;
    intLinkedList oddsList;

    cout << "Enter a list of integers ending with -999: ";
    int num;
    while (cin >> num && num != -999) {
        originalList.insert(num);
    }

    originalList.splitEvensOddsList(evensList, oddsList);
    displayEvensOdds(evensList, oddsList);

    return 0;
}

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    Node<int>* current = this->getHead();
    Node<int>* lastEven = nullptr;
    Node<int>* lastOdd = nullptr;

    while (current != nullptr) {
        Node<int>* nextNode = current->next;
        if (current->info % 2 == 0) {
            if (evensList.getHead() == nullptr) {
                evensList.setHead(current);
            }
            else {
                lastEven->next = current;
            }
            lastEven = current;
        }
        else {
            if (oddsList.getHead() == nullptr) {
                oddsList.setHead(current);
            }
            else {
                lastOdd->next = current;
            }
            lastOdd = current;
        }
        current->next = nullptr;
        current = nextNode;
    }

    this->setHead(nullptr);
}
