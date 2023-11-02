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

    // Verify first Absorption Law: p || (p && q) == p
    cout << "Verifying first Absorption Law: p || (p && q) == p\n";
    cout << "p | q | p && q | p || (p && q) | p\n";
    cout << "--|---|--------|--------------|---\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            p = i;
            q = j;
            bool lhs = p || (p && q);
            bool rhs = p;
            cout << p << " | " << q << " | " << (p && q) << "      | " << lhs << "            | " << rhs << "\n";
        }
    }

    // Verify second Absorption Law: p && (p || q) == p
    cout << "\nVerifying second Absorption Law: p && (p || q) == p\n";
    cout << "p | q | p || q | p && (p || q) | p\n";
    cout << "--|---|--------|--------------|---\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            p = i;
            q = j;
            bool lhs = p && (p || q);
            bool rhs = p;
            cout << p << " | " << q << " | " << (p || q) << "      | " << lhs << "            | " << rhs << "\n";
        }
    }

    
    //exit
    return 0;
}

