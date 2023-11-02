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
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    const int NUM_TRIALS = 1000000;
    const int NUM_CARDS = 52;
    const int NUM_VALUES = 13;
    int deck[NUM_CARDS];

    int countOther = 0, count1Pair = 0, count2Pair = 0, count3Kind = 0, count4Kind = 0;

    // Initialize deck
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i % NUM_VALUES + 1;
    }

    for (int t = 0; t < NUM_TRIALS; t++) {
        int drawnCards[4];

        // Draw four cards
        int drawnIndices[NUM_CARDS];
        for (int i = 0; i < NUM_CARDS; i++) {
            drawnIndices[i] = i;
        }
        random_shuffle(drawnIndices, drawnIndices + NUM_CARDS);
        for (int i = 0; i < 4; i++) {
            drawnCards[i] = deck[drawnIndices[i]];
        }

        // Check hand
        int valueCounts[NUM_VALUES] = {0};
        for (int i = 0; i < 4; i++) {
            valueCounts[drawnCards[i] - 1]++;
        }

        int pairCount = 0, tripleCount = 0, quadCount = 0;
        for (int i = 0; i < NUM_VALUES; i++) {
            if (valueCounts[i] == 2) pairCount++;
            else if (valueCounts[i] == 3) tripleCount++;
            else if (valueCounts[i] == 4) quadCount++;
        }

        if (quadCount) count4Kind++;
        else if (tripleCount) count3Kind++;
        else if (pairCount == 2) count2Pair++;
        else if (pairCount == 1) count1Pair++;
        else countOther++;
    }

    cout << "4 of a kind: " << (float)count4Kind / NUM_TRIALS * 100 << "%" << endl;
    cout << "3 of a kind: " << (float)count3Kind / NUM_TRIALS * 100 << "%" << endl;
    cout << "2 pair: " << (float)count2Pair / NUM_TRIALS * 100 << "%" << endl;
    cout << "1 pair: " << (float)count1Pair / NUM_TRIALS * 100 << "%" << endl;
    cout << "other: " << (float)countOther / NUM_TRIALS * 100 << "%" << endl;

    return 0;
}

