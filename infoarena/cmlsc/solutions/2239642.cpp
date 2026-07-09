//
//  LongestSubsequence.cpp
//  InfoArena
//
//  Created by Tim Palade on 9/11/18.
//  Copyright © 2018 Tim Palade. All rights reserved.
//

#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

#define NMax 1025

stack<int> a;

int D[NMax][NMax], M, N, A[NMax], B[NMax];

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
    
    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            }
            else {
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }
    
    i = M;
    j = N;
    
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            a.push(A[i]);
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
    
    //    for (j = 0; j <= N; j ++) {
    //        for (i = 0; i <= M; i ++) {
    //            cout << D[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    
    printf("%d\n", D[M][N]);
    for (; !a.empty(); a.pop()) {
        printf("%d ", a.top());
    }
    
    return 0;
}
