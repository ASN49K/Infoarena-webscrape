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

int gcd(int a, int b){
    if (!b)
        return a;
    gcd(b, a % b);
}

int main(int argc, char** argv) {
    int numberOfPairs;
    ifstream inputFile ("euclid2.in");
    ofstream outputFile ("euclid2.out");
    inputFile >> numberOfPairs;
    int a, b;
    while (numberOfPairs--){
        inputFile >> a;
        inputFile >> b;
        outputFile<<gcd(a, b)<<endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}