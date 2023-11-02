/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    dstryLst();
}

void LinkedList::push_front(int value) {
    Link* newLink = new Link;
    newLink->data = value;
    newLink->lnkNext = head;
    head = newLink;
}

void LinkedList::push_back(int value) {
    Link* newLink = new Link;
    newLink->data = value;
    newLink->lnkNext = nullptr;

    if (!head) {
        head = newLink;
    } else {
        Link* current = head;
        while (current->lnkNext) {
            current = current->lnkNext;
        }
        current->lnkNext = newLink;
    }
}

void LinkedList::pop_front() {
    if (head) {
        Link* temp = head;
        head = head->lnkNext;
        delete temp;
    }
}

void LinkedList::pop_back() {
    if (head) {
        if (!head->lnkNext) {
            delete head;
            head = nullptr;
        } else {
            Link* current = head;
            while (current->lnkNext && current->lnkNext->lnkNext) {
                current = current->lnkNext;
            }
            delete current->lnkNext;
            current->lnkNext = nullptr;
        }
    }
}

void LinkedList::prntLst() const {
    Link* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->lnkNext;
    }
    cout << "nullptr" << endl;
}

void LinkedList::dstryLst() {
    while (head) {
        pop_front();
    }
}
