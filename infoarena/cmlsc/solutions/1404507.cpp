#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "cmlsc";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif

const int NMAX = 1024 + 6;

int N, M;
int A[NMAX];
int B[NMAX];
int DP[NMAX][NMAX];

void afis(int i, int j) {
    if(!i || !j)
        return;

    if(A[i] == B[j]) {
        afis(i - 1, j - 1);
        printf("%d ", A[i]);
        return;
    }

    if(DP[i - 1][j] < DP[i][j - 1]) afis(i, j - 1);
    else afis(i - 1, j);
}

int main() {
    int i, j;

#ifndef ONLINE_JUDGE
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);
#endif

    scanf("%d%d", &N, &M);

    for(i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for(i = 1; i <= M; i++)
        scanf("%d", &B[i]);

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    printf("%d\n", DP[N][M]);

    afis(N, M);

    return 0;
}
