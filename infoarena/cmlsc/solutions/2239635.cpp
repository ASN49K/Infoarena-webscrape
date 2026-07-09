//
//  LongestSubsequence.cpp
//  InfoArena
//
//  Created by Tim Palade on 9/11/18.
//  Copyright © 2018 Tim Palade. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

#define NMax 1024
#define MAX(a,b) ((a > b) ? a : b)

int D[NMax][NMax], M, N, A[NMax], B[NMax], a[NMax];

void buildMatrix() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; i <= N; i++) {
            if (A[i] == B[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            }
            else {
                D[i][j] = MAX(D[i-1][j], D[i][j-1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int i ,j;
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; i++) {
        scanf("%d", &A[i]);
    }
    
    for (i = 1; i <= N; i++) {
        scanf("%d", &B[i]);
    }
    
    buildMatrix();
    
    i = M;
    j = N;
    int count = 0;
    
    while (i != 0 && j != 0) {
        if (A[i] == B[j]) {
            a[++count] = A[i];
            i--;
            j--;
        }
        else if (D[i-1][j] < D[i][j-1]) {
            j--;
        }
        else {
            i--;
        }
    }
    
    printf("%d\n", count);
    for (int i = count; i > 0; i--) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
