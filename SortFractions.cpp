#include "SortFractions.hpp"
#include <algorithm>
#include <iostream>

int gcd(int a, int b);
bool isFirstLessThanSecond(int* fracA, int* fracB);


void bubbleSortFractions(int** fracList, int listSize) {
    // TODO: Implement this function using bubble sort according to the specifications written in the assignment.
    // input: fracList - a list of fractions, each represented as an array of 4 integers.
    //        listSize - the number of fractions in the list.
    // output: The function should sort the fractions in-place in the fracList according to the 'natural zig-zag matching between natural numbers and rational numbers'.
    // You may assume that there are no duplicate fractions in the input list, but different fractions with the same value may exist (e/g. 1/2 and 2/4).
    // For your reference, the reference solution has somewhere between 50-80 lines of code, including the helper functions.
    if (listSize <= 1) return;

    int totalPairs = listSize;

    for (int i = 0; i < totalPairs; ++i) {
        fracList[2 * i + 1] = fracList[2 * i];
    }

    for (int i = 0; i < totalPairs - 1; ++i) {
        for (int j = 0; j < totalPairs - 1; ++j) {

            int* fracA = fracList[2 * j];
            int* fracB = fracList[2 * (j + 1)];

            if (!isFirstLessThanSecond(fracA, fracB)) {

                std::swap(fracList[2 * j], fracList[2 * (j + 1)]);
                std::swap(fracList[2 * j + 1], fracList[2 * (j + 1) + 1]);

                fracA[2]++;
                fracB[2]++;
            }
        }
    }
}

// Space for any helper functions you might want to add.
// Note: Having a print function may be greatly helpful for debugging!

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

bool isFirstLessThanSecond(int* fracA, int* fracB) {
    int Na = fracA[0]; 
    int Da = fracA[1];
    int Nb = fracB[0]; 
    int Db = fracB[1]; 

    if ((ll)Na * Db == (ll)Nb * Da) {
        return Na < Nb; [cite:336]
    }

    int G_A = gcd(Na, Da);
    int N_prime_A = Na / G_A;
    int D_prime_A = Da / G_A;

    int G_B = gcd(Nb, Db);
    int N_prime_B = Nb / G_B;
    int D_prime_B = Db / G_B;

    int SumA = N_prime_A + D_prime_A;
    int SumB = N_prime_B + D_prime_B;

    if (SumA != SumB) {
        return SumA < SumB;
    }

    if (SumA % 2 != 0) { 
        return N_prime_A < N_prime_B; 
    }
    else { 
        return D_prime_A < D_prime_B; 
    }
}