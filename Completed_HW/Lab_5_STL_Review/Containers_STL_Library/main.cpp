/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on October 24, 2023, 6:23 PM
 */

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

void examplePair();
void exampleList();
void exampleStack();
void exampleQueue();
void exampleSet();
void exampleMap();

int main() {
    int choice;
    do {
        cout << endl;
        cout << "Select a container example:" << endl;
        cout << "1. Pair" << endl;
        cout << "2. List" << endl;
        cout << "3. Stack" << endl;
        cout << "4. Queue" << endl;
        cout << "5. Set" << endl;
        cout << "6. Map" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << endl;
                examplePair();
                break;
            case 2:
                cout << endl;
                exampleList();
                break;
            case 3:
                cout << endl;
                exampleStack();
                break;
            case 4:
                cout << endl;
                exampleQueue();
                break;
            case 5:
                cout << endl;
                exampleSet();
                break;
            case 6:
                cout << endl;
                exampleMap();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 7);

    return 0;
}


void examplePair() {
    cout << "======= PAIR =======" << endl;
    int a;
    string b;
    cout << "Enter an integer: ";
    cin >> a;
    cout << "Enter a string: ";
    cin >> b;

    pair<int, string> p = make_pair(a, b);
    cout << "You created a pair: " << endl;
    cout << "Key: " << p.first << ", Value: " << p.second << endl << endl;
}

void exampleList() {
    cout << "======= LIST =======" << endl;
    list<int> l;
    int n, val;
    cout << "How many integers would you like to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> val;
        l.push_back(val);
    }

    cout << "Your list: ";
    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); it++) cout << *it << " ";
    cout << endl << endl;
}

void exampleStack() {
    cout << "======= STACK =======" << endl;
    stack<int> s;
    int choice, val;

    do {
        cout << "1. Push to stack\n2. Pop from stack\n3. Display top\n4. Done" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                if (!s.empty()) {
                    cout << "Popped value: " << s.top() << endl;
                    s.pop();
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 3:
                if (!s.empty()) {
                    cout << "Top of stack: " << s.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
        }
    } while (choice != 4);

    cout << endl;
}

void exampleQueue() {
    cout << "======= QUEUE =======" << endl;
    queue<int> q;
    int choice, val;

    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display front\n4. Done" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.push(val);
                break;
            case 2:
                if (!q.empty()) {
                    cout << "Dequeued value: " << q.front() << endl;
                    q.pop();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3:
                if (!q.empty()) {
                    cout << "Front of queue: " << q.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
        }
    } while (choice != 4);

    cout << endl;
}

void exampleSet() {
    cout << "======= SET =======" << endl;
    set<int> s;
    int n, val;
    cout << "Enter numbers (0 to stop): ";

    do {
        cin >> val;
        if (val != 0) {
            s.insert(val);
        }
    } while (val != 0);

    cout << "Unique numbers in your set: ";
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++) cout << *it << " ";
    cout << endl << endl;
}

void exampleMap() {
    cout << "======= MAP =======" << endl;
    map<int, string> m;
    int n, key;
    string value;

    cout << "How many key-value pairs would you like to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter key (integer) for pair " << i + 1 << ": ";
        cin >> key;
        cout << "Enter value (string) for pair " << i + 1 << ": ";
        cin >> value;
        m[key] = value;
    }

    cout << "Your map:" << endl;
    map<int, string>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;
}
