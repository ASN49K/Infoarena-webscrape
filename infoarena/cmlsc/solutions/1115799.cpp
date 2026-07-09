//#include "stdafx.h"

#include <fstream>
#include <iostream>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

#define NMAX 1024
#define MAX_VAL(a,b) ((a < b) ? b : a)

int main()
{
    // Read in M and N
    int M, N;
    in >> M >> N;

    // Read in vectors
    int A[NMAX], B[NMAX];
    for(int i = 1 ; i <= M; ++i)
        in >> A[i];
    for(int i = 1 ; i <= N; ++i)
        in >> B[i];

    // Construct the C matrix
    int C[NMAX][NMAX];
    for(int i = 1 ; i <= M; ++i)
        for(int j = 1; j <= N; ++j)
            if (A[i] == B[j])
                C[i][j] = 1 + C[i-1][j-1];
            else 
                C[i][j] = MAX_VAL(C[i][j-1], C[i-1][j]);

    // Backtrack to get the sequence
    int D[NMAX];
    int i = M;
    int j = N;
    int k = 0;
    while(i > 0 && j > 0)
    {
        if (A[i] == B[j])
        {
            D[k] = A[i];
            i--;
            j--;
            k++;
        } 
        else if (C[i][j-1] > C[i-1][j])
            j--;
        else 
            i--;
    }

    out << k << '\n';
    for (int i = k-1; i >= 0; i--)
    {
        out << D[i] << ' ';
    }

    return 0;
}
