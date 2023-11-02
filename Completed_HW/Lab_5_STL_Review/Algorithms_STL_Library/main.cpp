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
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void exampleShuffle();
void exampleSort();
void exampleFind();
void exampleMin();
void exampleMax();

int main() {
    int choice;
    do {
        cout << endl;
        cout << "Select an algorithm example:" << endl;
        cout << "1. Shuffle" << endl;
        cout << "2. Sort" << endl;
        cout << "3. Find" << endl;
        cout << "4. Min" << endl;
        cout << "5. Max" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << endl;
                exampleShuffle();
                break;
            case 2:
                cout << endl;
                exampleSort();
                break;
            case 3:
                cout << endl;
                exampleFind();
                break;
            case 4:
                cout << endl;
                exampleMin();
                break;
            case 5:
                cout << endl;
                exampleMax();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 6);

    return 0;
}


void exampleShuffle() {
    cout << "======= SHUFFLE =======" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Original vector: ";
    for(int i : v) cout << i << " ";
    
    srand(time(0));
    random_shuffle(v.begin(), v.end());
    
    cout << endl;
    cout << "Shuffled vector: ";
    for(int i : v) cout << i << " ";
    cout << endl << endl;
}

void exampleSort() {
    cout << "======= SORT =======" << endl;
    vector<int> v;
    int n, val;
    cout << "How many integers would you like to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    cout << "Sorted vector: ";
    for(int i : v) cout << i << " ";
    cout << endl << endl;
}

void exampleFind() {
    cout << "======= FIND =======" << endl;
    vector<int> v = {17, 23, 73, 43, 6, 16, 12, 21, 90, 83};
    cout << "Vector contents: ";
    for (int i : v) cout << i << " ";
    cout << endl;

    int val;
    cout << "Which value would you like to find? ";
    cin >> val;

    vector<int>::iterator it = find(v.begin(), v.end(), val);
    if(it != v.end()) {
        cout << "Value found at position " << distance(v.begin(), it) + 1 << endl;
    } else {
        cout << "Value not found in the vector" << endl;;
    }
    cout << endl;
}

void exampleMin() {
    cout << "======= MIN =======" << endl;
    vector<int> v;
    int n, val;
    cout << "How many integers would you like to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> val;
        v.push_back(val);
    }

    int minimum = *min_element(v.begin(), v.end());
    cout << "Minimum value in the vector: " << minimum << endl << endl;
}

void exampleMax() {
    cout << "======= MAX =======" << endl;
    vector<int> v;
    int n, val;
    cout << "How many integers would you like to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> val;
        v.push_back(val);
    }

    int maximum = *max_element(v.begin(), v.end());
    cout << "Maximum value in the vector: " << maximum << endl << endl;
}