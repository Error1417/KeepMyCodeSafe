/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Purpose: Interest calculator
 * 
 * Lecture WOD: MLTO
 * Lab WOD: Spreadsheet
 *
 * Created on March 12, 2022, 10:16 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

const unsigned char PERCENT = 100.0f;

/*
 * 
 */
int main(int argc, char** argv) 
{
    float bal, // The initial balance
          intrst, // Interest rate is 6%
          intrBal; // Interest balance 
    unsigned char numYers; // Number of compounding years
    
    
    bal = 100;
    intrst = 6;
    numYers = 12;
    
    
    intrst /= PERCENT;
    intrBal = bal * pow((1+intrst), numYers);
    
    cout << fixed << setprecision(2) << showpoint;
    cout << "Value after 12 Years = " << intrBal << endl;
    
    
    return 0;
}

