//
//  main.cpp
//  cmlsc
//
//  Created by Hai Tran Bach on 10/8/14.
//  Copyright (c) 2014 Hai Tran Bach. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 1024

int lcs[MAX + 1][MAX + 1][2];

int main() {
    
    
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    
    int v1[MAX + 1], v2[MAX + 1], v3[MAX+1];
    int lung1, lung2;
    
    in >> lung1 >> lung2;
    
    for (int i = 1; i <= lung1; ++i) {
        in >> v1[i];
    }
    for (int i = 1; i <= lung2; ++i) {
        in >> v2[i];
    }
    
    for (int i = 1; i <= lung1; ++i) {
        for (int j = 1; j <= lung2; ++j) {
            if (v1[i] == v2[j]) {
                lcs[i][j][0] = lcs[i-1][j-1][0] + 1;
                lcs[i][j][1] = 1;
            }
            else if (lcs[i-1][j][0] > lcs[i][j-1][0]) {
                lcs[i][j][0] = lcs[i-1][j][0];
                lcs[i][j][1] = 2;
            }
            else {
                lcs[i][j][0] = lcs[i][j-1][0];
                lcs[i][j][1]=3;
            }
        }
    }
    
    int i = lung1, j = lung2 , lung_max = 0;
    
    out << lcs[lung1][lung2][0] << "\n";
    
    while(lcs[i][j][0]) {
        if (lcs[i][j][1] == 1) {
            v3[++lung_max] = v1[i];
            --i;
            --j;
        }
        else if (lcs[i][j][1] == 2) {
            --i;
        }
        else {
            --j;
        }
    }
    
    for (int i = lung_max; i >= 1; --i) {
        out << v3[i] << " ";
    }

    out << "\n";
    return 0;
}
