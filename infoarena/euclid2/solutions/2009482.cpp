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

using namespace std;

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

int main(int argc, char** argv) {
    cout<<euclid(350,200);
    return 0;
}

