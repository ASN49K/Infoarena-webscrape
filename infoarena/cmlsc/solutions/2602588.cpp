#include <bits/stdc++.h>

using namespace std;

#define NMax 1024

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], best;

int main()
{
    int i, j;

    f >> M >> N;
    for(i = 1; i <= M; i++) f >> A[i];
    for(i = 1; i <= N; i++) f >> B[i];

    for(i = 1; i <= M; i++)
    for(j = 1; j <= N; j++)
    if (A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
    else D[i][j] = max(D[i-1][j], D[i][j-1]);

    for(i = M, j = N; i; )
    if (A[i] == B[j]) sir[++best] = A[i], --i, --j;
    else if (D[i-1][j] < D[i][j-1]) --j;
    else --i;

    g << best << '\n';
    for (i = best; i; --i) g << sir[i] << " ";

    f.close();
    g.close();
    return 0;
}
