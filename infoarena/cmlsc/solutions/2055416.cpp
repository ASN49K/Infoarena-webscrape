#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[101], b[101], n, m;
int lcs[101][101], rez[1005], k;
/**
    lcs(i,j) - lng max a unui subsir obtinut din a[1...i] si b[1...j];
    Solutia:
        lcs(n, m);
*/
void Citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
}
void Constr()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
}
void Afisare()
{
    fout << lcs[n][m] << "\n";
    int i, j;
    i = n;
    j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
            rez[++k] = a[i],
            i--,
            j--;
        else
        {
            if(lcs[i - 1][j] < lcs[i][j - 1]) j--;
            else i--;
        }
    }

    for(i = k ; i >= 1; i--)
        fout << rez[i] << " ";
}
int main()
{
    Citire();
    Constr();
    Afisare();
    return 0;
}
