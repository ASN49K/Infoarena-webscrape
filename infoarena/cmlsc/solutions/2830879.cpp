#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1025;

int n, m;

int a[MAX], b[MAX], M[MAX][MAX];
int numere[MAX], k;

void CMLSC(int m, int n)
{
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(a[i] == b[j])
                M[i][j] = M[i - 1][j - 1] + 1;
            else
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
        }
    /*for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            fout << M[i][j] << " ";
        fout << "\n";*/
    fout << M[m][n] << "\n";
    for(int i = m, j = n; i >= 1 && j >= 1;)
        {
            if(a[i] == b[j])
            {
                numere[++ k] = a[i];
                i --;
                j --;
            }
            else if(M[i - 1][j] < M[i][j - 1])
                j --;
            else
                i --;
        }
    for(int i = k; i >= 1; i --)
        fout << numere[i] << " ";
}

int main()
{
    //ios_base::sync_with_stdio(false);
   // fin.tie(NULL);

    fin >> m >> n;
    for(int i = 1; i <= m; i ++)
        fin >> a[i];
    for(int i = 1; i <= n; i ++)
        fin >> b[i];

    CMLSC(m, n);
    return 0;
}
