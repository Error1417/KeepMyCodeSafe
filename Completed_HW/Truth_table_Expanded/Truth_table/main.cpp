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

using namespace std;

//global constants

//user libraries



//execution starts here
int main(int argc, char** argv) {
    //random seed goes here
    
    //declare variables
    
    //initialize variables
    
    //the process -> map inputs to output
    
    //display inputs/output
    cout << " p  q  ~p  ~q  p&&q  p||q  p^q  p^q^q  p^q^p  !(p&&q)  !p||!q  !(p||q)  !p^!q" << endl;
    //de-allocate memory
   for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            cout << " " << p 
                 << "  " << q 
                 << "   " << !p 
                 << "   " << !q 
                 << "    " << (p && q) 
                 << "     " << (p || q) 
                 << "    " << (p ^ q) 
                 << "     " << (p ^ q ^ q) 
                 << "      " << (p ^ q ^ p) 
                 << "       " << !(p && q) 
                 << "       " << (!p || !q) 
                 << "        " << !(p || q) 
                 << "      " << (!p ^ !q) 
                 << endl;
        }
    }
    //exit
    return 0;
}

