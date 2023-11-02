/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: error
 *
 * Created on March 25, 2023, 2:15 PM
 */

#include <iostream>
#include <stdlib.h>     //for using the function sleep
#include "Date.h"
#include "Time.h"

using namespace std;

int main() {
    
    Date today; // keeps track of the date
    Time now; // keeps track of current time
    
    today.printDate();//print function for the date
    now.printTime(); // print function for the time
    

    return 0;
}

