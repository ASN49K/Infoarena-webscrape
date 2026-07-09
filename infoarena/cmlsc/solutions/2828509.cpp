#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1025;

int n, m;

int _1[MAX], _2[MAX], M[MAX][MAX];
int numere[MAX], k;

void CMLSC(int m, int n)
{
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(_1[i] == _2[j])
                M[i][j] = M[i - 1][j - 1] + 1;
            else
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
        }
    /*for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n; j ++)
            fout << M[i][j] << " ";
        fout << "\n";*/
    fout << M[m][n] << "\n";
    for(int i = m; i >= 1; i --)
        for(int j = n; j >= 1; j --)
        {
            if(_1[i] == _2[j])
            {
                numere[++ k] = _1[i];
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
        fin >> _1[i];
    for(int i = 1; i <= n; i ++)
        fin >> _2[i];

    CMLSC(m, n);
    return 0;
}
