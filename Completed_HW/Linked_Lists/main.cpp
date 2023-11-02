/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on October 25, 2023, 6:57 PM
 */

 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// Function prototypes
void push(Node** head_ref, int new_data);
void insertAfter(Node* prev_node, int new_data);
void append(Node** head_ref, int new_data);
void printList(Node* node);
void insertSorted(Node** head_ref, int new_data);
Node* query(Node** head_ref, int value);

int main() {
    Node* head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    cout << "Created DLL is: ";
    printList(head);

    cout << endl << "Inserting in sorted manner: ";
    insertSorted(&head, 5);
    printList(head);

    cout << endl << "Querying for value 4: ";
    query(&head, 4);
    printList(head);

    return 0;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "previous node cannot be NULL" << endl;
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void printList(Node* node) {
    Node* last;
    cout << endl << "Forward: ";
    while (node != NULL) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << endl << "Reverse: ";
    while (last != NULL) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

void insertSorted(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = new_node->prev = NULL;

    if (!*head_ref || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        if (*head_ref) {
            (*head_ref)->prev = new_node;
        }
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    while (current->next && current->next->data < new_data) {
        current = current->next;
    }

    new_node->next = current->next;
    if (current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    new_node->prev = current;
}

Node* query(Node** head_ref, int value) {
    Node* temp = *head_ref;
    while (temp) {
        if (temp->data == value) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            temp->next = *head_ref;
            temp->prev = NULL;
            if (*head_ref) {
                (*head_ref)->prev = temp;
            }
            *head_ref = temp;
            return temp;
        }
        temp = temp->next;
    }
    cout << "Value not found in the list" << endl;
    return NULL;
}

