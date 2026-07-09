/**
    Given the lengths M and N of two sequences A and B, find the length of the longest common subsequence and print the found sequence. 
	1 <= M, N <= 1024
**/

#include <cstdio>
#include <algorithm>
 
#define NMAX 1025
 
using namespace std;
 
int M, N;
int A[NMAX], B[NMAX];
int DP[NMAX][NMAX], LCS[NMAX];
 
void read() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &B[i]);
    }
}
 
void dynamicProgramming() {
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i] == B[j]) {
            	DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
            	DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
		}
	}
}
 
void tracebackLCS() {
    for (int i = M, j = N; i >= 1 && j >= 1;) {
        if (A[i] == B[j]) {
            LCS[++LCS[0]] = A[i];
            i--;
            j--;
        }
        else if (DP[i - 1][j] > DP[i][j - 1]) {
        	i--;
        }
        else {
        	j--;
        }
    }
}
 
void print() {
    printf("%d\n", DP[M][N]);

    for (int i = LCS[0]; i >= 1; --i) {
        printf("%d ", LCS[i]);
    }
}
 
int main() {
    read();
    dynamicProgramming();
    tracebackLCS();
    print();
}