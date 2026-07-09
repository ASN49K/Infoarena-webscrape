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

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')
#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "cmlsc";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif // HOME

typedef long long int lld;
typedef pair<int, int> PII;
typedef pair<int, lld> PIL;
typedef pair<lld, int> PLI;
typedef pair<lld, lld> PLL;

const int INF = (1LL << 31) - 1;
const lld LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MOD = (int)(1e9) + 7;

const int NMAX = 1024 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;

int N, M;
int A[NMAX];
int B[NMAX];
int DP[NMAX][NMAX];

void write(int i, int j) {
    if(i == 0 || j == 0)
        return;

    if(A[i] == B[j]) {
        write(i - 1, j - 1);
        printf("%d ", A[i]);
    } else if(DP[i][j] == DP[i - 1][j])
        write(i - 1, j);
    else
        write(i, j - 1);
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
            if(A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    printf("%d\n", DP[N][M]);

    write(N, M);

    return 0;
}
