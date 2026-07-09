/* 
 * File:   main.cpp
 * Author: manuel
 *
 * Created on October 28, 2011, 8:33 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;
int gcd(int a, int b);
/*
 * 
 */
int main(int argc, char** argv) {
    int numberOfPairs = 0;
    ifstream inputFile ("euclid2.in");
    ofstream outputFile ("euclid2.out");
    inputFile >> numberOfPairs;
    int a = 0, b = 0;
    int greatestDivisor = 0;
    for (unsigned short i = 1; i <= numberOfPairs; i++){
        inputFile >> a;
        inputFile >> b;
        greatestDivisor = gcd(a, b);
        outputFile<<greatestDivisor<<endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    gcd(b, a % b);
}