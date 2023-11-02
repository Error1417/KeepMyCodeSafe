/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on November 1, 2023, 7:16 PM
 * 
 * +++++I am not sure if the output if correct for this one.+++++++
 * 
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

float C(float x);
float S(float x);
float derivativeOfSquaredS(float x);

int main() {
    float x = 0.1f;
    float upper_bound = atan(1.0);

    while (x <= upper_bound) {
        cout << "C(" << x << ") = " << C(x) << "\nS(" << x << ") = " << S(x) << endl << endl;
        x += 0.1f;
    }

    return 0;
}

float C(float x) {
    float tol = 1e-6;
    if (abs(x) < tol) {
        return (1 / x) + x / 6;
    } else {
        return 0.5 * C(x / 2) * S(x / 2);
    }
}

float S(float x) {
    float tol = 1e-6;
    if (abs(x) < tol) {
        return 1 + x * x / 2;
    } else {
        float cVal = C(x / 2);
        float sVal = S(x / 2);
        return (cVal * cVal * sVal) / (cVal * cVal - derivativeOfSquaredS(x / 2));
    }
}

float derivativeOfSquaredS(float x) {
    return 2*x + x*x*x;
}