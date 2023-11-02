/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on October 25, 2023, 7:27 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

unsigned long long factorial(int);
string formatNumber(unsigned long long);

int main() {
    
    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<"N M P Rep P no Rep C Rep C no Rep"<<endl;
    cout<<"N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;
    cout<< endl;
    
    
    
    // Output the headers
    cout << setw(5) << "N" << setw(5) << "M" << setw(25) << "Permutation" << setw(25) << "Perm with Replacement"
         << setw(25) << "Combination" << setw(30) << "Comb with Replacement" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

    // Loop through the desired range for n and m
    for(int n = 2; n <= 26; n++) {
        for(int m = 0; m <= n; m++) {
            unsigned long long perm = factorial(n) / factorial(n - m);
            unsigned long long permRep = pow(n, m);
            unsigned long long comb = factorial(n) / (factorial(m) * factorial(n - m));
            unsigned long long combRep = factorial(n + m - 1) / (factorial(m) * factorial(n - 1));

            // Output the results
            cout << setw(5) << n << setw(5) << m 
                 << setw(25) << formatNumber(perm) 
                 << setw(25) << formatNumber(permRep) 
                 << setw(25) << formatNumber(comb) 
                 << setw(30) << formatNumber(combRep) << endl;
        }
    }

    return 0;
}


// function to calculate factorial
unsigned long long factorial(int n) {
    if(n <= 1) return 1;
    else return n * factorial(n-1);
}

// function to convert number to "a x 10^b" format for numbers with exponents greater than 5
string formatNumber(unsigned long long num) {
    if(num == 0) return "0";
    
    int exponent = log10(num);
    
    if (exponent > 5) {
        float m = static_cast<float>(num) / pow(10, exponent);
        char buffer[50];
        sprintf(buffer, "%.2lfx10^%d", m, exponent);
        return buffer;
    }
    else {
        return to_string(num);
    }
}





