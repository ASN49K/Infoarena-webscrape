#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdio.h>

#define SIZE 1025

using namespace std;

int A[SIZE];
int B[SIZE];
int RES[SIZE];

int SUB[SIZE][SIZE];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int M, N;
    scanf("%d %d", &M, &N);
    for(int i = 0; i < SIZE; i++) {A[i] = 0; B[i] = 0; RES[i] = 0;}
    for(int i = 1; i < M + 1; i++) scanf("%d", &(A[i]));
    for(int i = 1; i < N + 1; i++) scanf("%d", &(B[i]));

    for(int i = 0; i < SIZE; i++) {SUB[i][0] = 0; SUB[0][i] = 0;}
    int c;

    if(M > N){
        for(int i = 1; i <= N; i++)
        {
            for(int j = i; j <= N; j++)
            {
                c = (SUB[i-1][j] > SUB[i][j-1]) ? SUB[i-1][j] : SUB[i][j-1];
                if(A[i] == B[j]) SUB[i][j] = ((SUB[i-1][j-1] + 1) > c) ? (SUB[i-1][j-1] + 1) : c;
                else SUB[i][j] = c;
            }
            for(int j = i; j <= M; j++)
            {
                c = (SUB[j-1][i] > SUB[j][i-1]) ? SUB[j-1][i] : SUB[j][i-1];
                if(A[j] == B[i]) SUB[j][i] = ((SUB[j-1][i-1] + 1) > c) ? (SUB[j-1][i-1] + 1) : c;
                else SUB[j][i] = c;
            }
        }
    }
    else {
        for(int i = 1; i <= M; i++)
        {
            for(int j = i; j <= M; j++)
            {
                c = (SUB[j-1][i] > SUB[j][i-1]) ? SUB[j-1][i] : SUB[j][i-1];
                if(A[j] == B[i]) SUB[j][i] = ((SUB[j-1][i-1] + 1) > c) ? (SUB[j-1][i-1] + 1) : c;
                else SUB[j][i] = c;
            }
            for(int j = i; j <= N; j++)
            {
                c = (SUB[i-1][j] > SUB[i][j-1]) ? SUB[i-1][j] : SUB[i][j-1];
                if(A[i] == B[j]) SUB[i][j] = ((SUB[i-1][j-1] + 1) > c) ? (SUB[i-1][j-1] + 1) : c;
                else SUB[i][j] = c;
            }
        }
    }

    int i = M, j = N;
    c = SUB[M][N];
    while(c > 0)
    {
        if (SUB[i][j-1] == SUB[i-1][j])
        {
            if (SUB[i][j] == SUB[i-1][j])
                --i;
            else {
                RES[c] = A[i];
                --i;
                --j;
                --c;
                }
        } else  if (SUB[i][j] == SUB[i-1][j])
                    --i;
                else --j;
    }

    printf("%d\n", SUB[M][N]);
    printf("%d", RES[1]);
    for (int i = 2; i <= SUB[M][N]; ++i)
        printf(" %d", RES[i]);
    //printf("\n");

/*
    for(int i = 0; i < M; i++) printf("%d ", A[i]);
    printf("\n");
    for(int i = 0; i < N; i++) printf("%d ", B[i]);
    printf("\n");
*/


    return 0;
}
