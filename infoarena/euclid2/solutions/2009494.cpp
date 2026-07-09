/* 
 * File:   main.cpp
 * Author: sopy
 *
 * Created on August 9, 2017, 8:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int temp, a, b;

/*
 * 
 */
int euclid(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    fin >> temp;
    while(temp){
    fin >> a >> b;
    fout << euclid(a, b) << '\n';
    temp--;
    }
    return 0;
}

