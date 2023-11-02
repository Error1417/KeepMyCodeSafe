/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael
 *
 * Created on August 23, 2023, 11:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//global constants

//user libraries



//execution starts here
int main(int argc, char** argv) {
    //random seed goes here
    
     bool p, q;

    // Verify first expression: (p && q) || ~(p || q) == ~(p ^ q)
    cout << "Verifying first expression: (p && q) || ~(p || q) == ~(p ^ q)\n";
    cout << "p | q | p && q | ~(p || q) | (p && q) || ~(p || q) | ~(p ^ q)\n";
    cout << "--|---|--------|-----------|-----------------------|--------\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            p = i;
            q = j;
            bool lhs = (p && q) || ~(p || q);
            bool rhs = ~(p ^ q);
            cout << p << " | " << q << " | " << (p && q) << "      | " << (~p || ~q) << "         | " << lhs << "                     | " << rhs << "\n";
        }
    }

    // Verify second expression: (p || q) && ~(p && q) == p ^ q
    cout << "\nVerifying second expression: (p || q) && ~(p && q) == p ^ q\n";
    cout << "p | q | p || q | ~(p && q) | (p || q) && ~(p && q) | p ^ q\n";
    cout << "--|---|--------|-----------|-----------------------|------\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            p = i;
            q = j;
            bool lhs = (p || q) && ~(p && q);
            bool rhs = p ^ q;
            bool nhs = ~(p && q);
            cout << p << " | " << q << " | " << (p || q) << "      | " << nhs << "         | " << lhs << "                     | " << rhs << "\n";
        }
    }

    
    //exit
    return 0;
}

