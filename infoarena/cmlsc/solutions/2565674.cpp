#include <bits/stdc++.h>

#define MAXN    1030

#define FILENAME    std::string("cmlsc")
std::ifstream input (FILENAME+".in");
std::ofstream output(FILENAME+".out");

int N, K;
int A[MAXN], B[MAXN];
int DP[MAXN][MAXN];

void print(int a = N, int b = K) {
    if (a == 0) return;
    if (A[a] == B[b]) {
        print(a-1, b-1);
        output << A[a] << ' ';
    }
    else {
        if (DP[a-1][b] > DP[a][b-1]) {
            print(a-1, b);
        }   else print (a, b-1);
    }
}

int main()
{
    input >> N >> K;
    for (int i=1; i<=N; ++i) input >> A[i];
    for (int i=1; i<=K; ++i) input >> B[i];
    for (int i=1, j; i<=N; ++i)
        for (j=1; j<=N; ++j)
        if (A[i] == B[j])
            DP[i][j] = DP[i-1][j-1] + 1;
        else
            DP[i][j] = std::max(DP[i-1][j], DP[i][j-1]);
    output << DP[N][K] << '\n';
    print();

    return 0;
}
