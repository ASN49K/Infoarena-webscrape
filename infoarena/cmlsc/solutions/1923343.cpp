#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n, m, *A, *B, **d;
    fin >> n >> m;

    A = (int*)malloc((n+1) * sizeof(int));
    B = (int*)malloc((m+1) * sizeof(int));
    d = (int**)malloc((n+1) * sizeof(int*));

    for (int i = 1; i <= n; ++i)
        fin >> A[i], d[i] = (int*)malloc(n * sizeof(int));

    for (int i = 1; i <= m; ++i)
        fin >> B[i];

     for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            d[i][j] = 0;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(A[i] ==  B[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j],d[i][j - 1]);

    fout << d[n][m] << "\n";

    int *sir = (int*)malloc(m*sizeof(int));
    sir[0] = 0;
    for(int i = n, j = m;i;)
        if (A[i] ==  B[j])
            sir[++sir[0]] = A[i], i--,j--;
        else
            if(d[i - 1][j] < d[i][j - 1])
                j--;
            else
                i--;
    for(int i = sir[0]; i; --i)
        fout << sir[i] << " ";

    free(sir);
    free(A);
    free(B);
    for (int i = 0; i <= n; ++i)
        free(d[i]);
    free(d);
    return 0;
}
