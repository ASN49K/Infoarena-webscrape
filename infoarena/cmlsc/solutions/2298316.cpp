#include <bits/stdc++.h>

#define MAXN 1030

int N, M;
int A[MAXN], B[MAXN];
int LCS[MAXN][MAXN];

void Dyn() {
    for (int i=1, j; i<=N; ++i)
        for (j=1; j<=M; ++j)
            if (A[i] == B[j])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = std::max(LCS[i-1][j], LCS[i][j-1]);
}

std::ifstream In("cmlsc.in");
std::ofstream Out("cmlsc.out");

int Best, Ans[MAXN];

void Citire() {
    In >> N >> M;
    for (int i=1; i<=N; ++i)
        In >> A[i];
    for (int i=1; i<=M; ++i)
        In >> B[i];
}

void Rezolvare() {
    Dyn();

    for (int i=N, j=M; i>0;) {
        if (A[i] == B[j])
            Ans[++ Best] = A[i],
            --i, --j;
        else if (LCS[i-1][j] < LCS[i][j-1])
            --j;
        else
            --i;
    }   Out << Best << '\n';
    for (int i=1; i<=Best; ++i)
        Out << Ans[Best-i+1] << ' ' ;
}

int main()
{
    Citire();
    Rezolvare();

    return 0;
}
