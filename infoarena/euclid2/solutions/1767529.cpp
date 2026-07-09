/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: daniel
 *
 * Created on 29 September 2016, 11:08
 */

#include <cstdlib>
#include <cstdio>

using namespace std;

int euclid(int a, int b) {
    int r = a % b;
//    printf("%d %d %d\n", a, b, r);
    if(r == 0) {
        return b;
    }
    else {
        return euclid(b, r);
    }
}


int main(int argc, char** argv) {
    
    int T;
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");

    fscanf(fin, "%d", &T);
//    printf("%d ", T);

    for(int i = 0 ; i < T ; i++) {
        int a, b;
        fscanf(fin, "%d %d", &a, &b);
        if(a < b) {
            int interim = a;
            a = b;
            b = interim;
        }
        fprintf(fout, "%d\n", euclid(a, b));
    }
    
    fclose(fin);
    fclose(fout);

    return 0;
}