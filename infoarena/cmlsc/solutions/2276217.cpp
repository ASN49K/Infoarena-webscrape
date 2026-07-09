#include <bits/stdc++.h>

using namespace std;
int a[1030] , b[1030] , lcs[1030][1030];
int n , m;
ofstream fout("cmlsc.out");
void Citire()
{
    int i , j;
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(j = 1; j <= m; j++)
        fin >> b[j];
    fin.close();
}
void Construire()
{
    int i , j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])lcs[i][j] = 1 + lcs[i - 1][j - 1];
                else lcs[i][j] = max(lcs[i - 1][j] , lcs[i][j - 1]);
    }
}
void Afisare()
{
    fout << lcs[n][m] << "\n";
}
void LCS(int i , int j)
{
    if(lcs[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            LCS(i - 1, j - 1);
            fout << a[i] << " ";
        }
        else
        {
            if(lcs[i - 1][j] > lcs[i][j - 1])LCS(i - 1, j);
            else LCS(i, j - 1);
        }
    }
}
int main()
{
    Citire();
    Construire();
    Afisare();
    LCS(n , m);
    fout.close();
    return 0;
}
