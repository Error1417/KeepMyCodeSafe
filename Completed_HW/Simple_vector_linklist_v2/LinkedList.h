/* 
 * File:   LinkedList.h
 * Author: Ismael Perez
 *
 * Created on October 18, 2023, 1:00 AM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
protected:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    LinkedList();
    ~LinkedList();

    Node<T>* getHead() const { return head; }
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    int size() const;
    T& operator[](int index);
    T& front();
    T& back();
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (count > 0) {
        pop_front();
    }
}

template <typename T>
void LinkedList<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }
    count++;
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->prev = tail;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == nullptr) {
        head = tail;
    }
    count++;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) return;

    Node<T>* temp = head;
    head = head->next;
    delete temp;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    count--;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (tail == nullptr) return;

    Node<T>* temp = tail;
    tail = tail->prev;
    delete temp;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    count--;
}

template <typename T>
int LinkedList<T>::size() const {
    return count;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
T& LinkedList<T>::front() {
    return head->data;
}

template <typename T>
T& LinkedList<T>::back() {
    return tail->data;
}
#endif /* LINKEDLIST_H */

