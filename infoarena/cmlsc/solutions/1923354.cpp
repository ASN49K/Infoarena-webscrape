#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NN = 1 << 10 + 1;
int d[NN][NN], A[NN], B[NN], sir[NN];
int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> A[i];

    for (int i = 1; i <= m; ++i)
        fin >> B[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i] ==  B[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j],d[i][j - 1]);

    fout << d[n][m] << "\n";

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
    return 0;
}

