/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    fin >> a >> b;
    fout << euclid(a, b) << '\n';
    return 0;
}

