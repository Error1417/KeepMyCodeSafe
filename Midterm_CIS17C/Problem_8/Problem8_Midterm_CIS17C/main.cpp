/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on November 1, 2023, 8:24 PM
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    const int VECTOR_SIZE = 100000; // Sizable vector for simulation
    const int TRIALS = 1000000; // Number of trials to run

    // Filling the vector with 40% 1s and 60% 0s
    vector<int> bVector(VECTOR_SIZE, 0);
    for(int i = 0; i < VECTOR_SIZE * 0.40; i++) {
        bVector[i] = 1;
    }
    random_shuffle(bVector.begin(), bVector.end()); // Shuffle the vector

    // Seed for randomness
    srand(time(nullptr));

    // Simulating
    int count = 0;
    for(int i = 0; i < TRIALS; i++) {
        int start = rand() % (VECTOR_SIZE - 4); // -4 to avoid accessing beyond the vector
        if(bVector[start] == 1 && 
           bVector[start + 1] == 1 &&
           bVector[start + 2] == 1 &&
           bVector[start + 3] == 1 &&
           bVector[start + 4] == 1) {
            count++;
        }
    }

    float simulatedProbability = static_cast<float>(count) / TRIALS;
    float calculatedProbability = pow(0.40, 5);

    cout << "Simulated Probability: " << simulatedProbability << endl;
    cout << "Calculated Probability: " << calculatedProbability << endl;

    return 0;
}


