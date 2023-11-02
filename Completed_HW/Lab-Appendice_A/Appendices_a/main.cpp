/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on September 8, 2023, 7:22 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float  C, sum = 0;
    int n, m;
   
    cout << "Enter in the value for C , n , m. (ex. 4 3 5)" << endl;
    cin >> C >> n >> m;
    
    //for loop solution
    for(int i = m; i <= n; i++) {
        sum += C;
    }
    
    cout << endl;
    cout << "For loop summing gives you: " << sum << endl;
    
    // formula solution
    sum = 0;
    sum = C * (n - m + 1);
 
    cout << "Answer from the formula gives you: " << sum << endl;
    
    return 0;
}

