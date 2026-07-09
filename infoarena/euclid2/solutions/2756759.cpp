//
//  alg_lui_euclid.cpp
//  probleme
//
//  Created by Mihnea Buzoiu on 6/2/21.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int f(int a, int b){
    if (a == b)
        return a;
    
    return f(b, a%b);
}

int main(int argc, const char * argv[]) {
    
    FILE * fin = fopen("euclid2.in", "r");
    FILE * fout = fopen("euclid2.out", "w");
    
    int t, a, b;
    fscanf(fin, "%d", &t);
    
    for (int i=0; i<t; i++){
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d", f(a, b));
    }
}
