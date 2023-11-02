/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on November 1, 2023, 7:25 PM
 */

#include <iostream>
#include <string>

using namespace std;

// Struct for storing numbers in scientific notation
struct SciNum {
    float mant;
    int exp;
};

// Function prototypes
SciNum power_lin(unsigned long long x, unsigned long long n);
SciNum power_log(unsigned long long x, unsigned long long n);
string toSci(const SciNum& num);

int main() {
    // Test case 1
    unsigned long long x1 = 2, n1 = 10;
    cout << "O(n): " << x1 << "^" << n1 << " = " << toSci(power_lin(x1, n1)) << endl;
    cout << "O(log n): " << x1 << "^" << n1 << " = " << toSci(power_log(x1, n1)) << endl;

    // Test case 2
    unsigned long long x2 = 5, n2 = 15;
    cout << "O(n): " << x2 << "^" << n2 << " = " << toSci(power_lin(x2, n2)) << endl;
    cout << "O(log n): " << x2 << "^" << n2 << " = " << toSci(power_log(x2, n2)) << endl;

    // Test case 3
    unsigned long long x3 = 7, n3 = 25;
    cout << "O(n): " << x3 << "^" << n3 << " = " << toSci(power_lin(x3, n3)) << endl;
    cout << "O(log n): " << x3 << "^" << n3 << " = " << toSci(power_log(x3, n3)) << endl;
    
    // Test case 4
    unsigned long long x4 = 15, n4 = 30;
    cout << "O(n): " << x4 << "^" << n4 << " = " << toSci(power_lin(x4, n4)) << endl;
    cout << "O(log n): " << x4 << "^" << n4 << " = " << toSci(power_log(x4, n4)) << endl;

    return 0;
}

SciNum mul(const SciNum& a, unsigned long long x) {
    SciNum r = {a.mant * x, a.exp};
    while (r.mant >= 10.0) {
        r.mant /= 10.0;
        r.exp++;
    }
    return r;
}

SciNum mul(const SciNum& a, const SciNum& b) {
    SciNum r = {a.mant * b.mant, a.exp + b.exp};
    while (r.mant >= 10.0) {
        r.mant /= 10.0;
        r.exp++;
    }
    return r;
}

SciNum power_lin(unsigned long long x, unsigned long long n) {
    if (n == 0) return {1.0, 0};
    return mul(power_lin(x, n-1), x);
}

SciNum power_log(unsigned long long x, unsigned long long n) {
    if (n == 0) return {1.0, 0};
    SciNum half = power_log(x, n/2);
    if (n % 2 == 0) return mul(half, half);
    return mul(mul(half, half), x);
}

string toSci(const SciNum& num) {
    return to_string(num.mant) + "E^" + to_string(num.exp);
}