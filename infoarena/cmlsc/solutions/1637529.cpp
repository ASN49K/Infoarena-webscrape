#include <bits/stdc++.h>
#define MAX 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[MAX], b[MAX], D[MAX][MAX], k, sir[MAX];

int main()
{
    fin >> m >> n;

    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                D[i][j] =  1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    for(int i = m, j = n; i;)
    {
        if(a[i] == b[j])
        {
            sir[++k] = a[i];
            i--;
            j--;
        }
        else if(D[i-1][j] < D[i][j-1])
            j--;
        else
            i--;
    }

    fout << k << '\n';
    for(int i = k; i; --i)
        fout << sir[i] << " ";

    return 0;
}
