/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: Ismael Perez
 *
 * Created on October 17, 2023, 5:14 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
private:
    struct Link {
        int data;
        Link* lnkNext;
    };
    Link* head;

public:
    LinkedList();
    ~LinkedList();
    
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void prntLst() const;
    void dstryLst();
};


#endif /* LINKEDLIST_H */

