/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on October 18, 2023, 12:59 AM
 */

#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main() {
    char choice;
    int value;
    
    SimpleVector<int> vec;
    
    vec.push_front(3);
    vec.push_front(2);
    vec.push_front(1);
    vec.push_front(2);
    vec.push_front(8);
    
    cout << "Current List: ";
    vec.print(); 
    cout << endl;


    do {
        cout << "\nOptions:\n";
        cout << "1. Push front\n";
        cout << "2. Push back\n";
        cout << "3. Pop front\n";
        cout << "4. Pop back\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to push to the front: ";
                cin >> value;
                vec.push_front(value);
                
                cout << endl;
                cout << "Updated List: ";
                vec.print();
                cout << endl;
                break;

            case '2':
                cout << "Enter value to push to the back: ";
                cin >> value;
                vec.push_back(value);
                
                cout << endl;
                cout << "Updated List: ";
                vec.print();
                cout << endl;
                break;

            case '3':
                vec.pop_front();
                cout << endl;
                cout << "Updated List (Popped from front): ";
                vec.print();
                cout << endl;
                break;

            case '4':
                vec.pop_back();
                cout << endl;
                cout << "Updated List (Popped from Back): ";
                vec.print();
                cout << endl;
                break;

            case '5':
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }

    } while (choice != '5');
    
    return 0;
}


