/* 
 * File:   SimpleVector.h
 * Author: Ismael Perez
 *
 * Created on October 18, 2023, 1:01 AM
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "LinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
class SimpleVector {
private:
    LinkedList<T> list;
    int capacity;

    void resize();

public:
    SimpleVector();
    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    void print() const;
};

template <typename T> //initial size
SimpleVector<T>::SimpleVector() : capacity(10) {}

template <typename T> // when the size gets close it doubles
void SimpleVector<T>::resize() {
    if (list.size() >= capacity) {
        capacity *= 2;
    }
}

template <typename T>
void SimpleVector<T>::push_back(T value) {
    resize();
    list.push_back(value);
}

template <typename T>
void SimpleVector<T>::push_front(T value) {
    resize();
    list.push_front(value);
}

template <typename T>
void SimpleVector<T>::pop_back() {
    if (list.size() > 0) {
        list.pop_back();
    }
}

template <typename T>
void SimpleVector<T>::pop_front() {
    if (list.size() > 0) {
        list.pop_front();
    }
}

template <typename T>
void SimpleVector<T>::print() const {
    Node<T>* currentNode = list.getHead();

    while (currentNode) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}
#endif /* SIMPLEVECTOR_H */

