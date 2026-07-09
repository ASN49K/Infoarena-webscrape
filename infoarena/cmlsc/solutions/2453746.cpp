//
//  main.cpp
//  cmlsc
//
//  Created by Danut Avadanei on 04/09/2019.
//  Copyright © 2019 ziende. All rights reserved.
//

#include <iostream>
#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024

using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax];

int main() {
    int i, j, k = 0;
    
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    
    fin >> M >> N;
    
    for (i = 1; i <= M; i++) {
        fin >> A[i];
    }
    
    for (i = 1; i <= N; i++) {
        fin >> B[i];
    }
    
    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);
            }
        }
    }
    
    fout << D[i - 1][j - 1] << endl ; // Max LCS
    
    for (i = M, j = N; i;) {
        if (A[i] == B[j]) {
            sir[++k] = A[i];
            i--;
            j--;
        } else if (D[i - 1][j] < D[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }
    
    for (i = k; i; --i) {
        fout << sir[i] << " ";
    }
    
    return 0;
}
