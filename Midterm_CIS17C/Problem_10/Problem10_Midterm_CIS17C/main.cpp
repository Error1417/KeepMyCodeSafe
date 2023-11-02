/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on November 1, 2023, 7:19 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the derivative of g(x) = x - x^3/6
float derivative(float);

// Recursive function g
float g(float);

int main() {
    //All possible Test Cases
    const int SIZE = 20;
    float x[SIZE] = {0.1f,0.2f,0.3f,0.4f,0.5f,0.6f,0.7f,0.8f,0.9f,1.0f
            ,-1.0f,-0.9f,-0.8f,-0.7f,-0.6f,-0.5f,-0.4f,-0.3f,-0.2f,-0.1f};
    
    for(int i = 0; i < SIZE; i++){
        cout << "g(" << x[i] << ") = " << g(x[i]) << endl;
    }
    
    return 0;
}

// Function to calculate the derivative of g(x) = x - x^3/6
float derivative(float x) {
    return 1 - x * x / 2;  // Derivative of x - x^3/6
}

// Recursive function g
float g(float x) {
    float tol = 1000000;  // Tolerance value
    if (abs(x) < tol) {
        return x - (x * x * x) / 6;
    } else {
        return (2 * g(x / 2)) / (1 + derivative(x / 2));
    }
}