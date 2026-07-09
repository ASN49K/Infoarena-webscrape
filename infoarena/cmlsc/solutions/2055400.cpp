#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1050], b[1050], lcs[1050][1050];
int n, m;
int t[1050], k;
void Citire()
{
    int i;

    fin >> n >> m;

    for(i = 1; i <= n; i++)
        fin >> a[i];

    for(i = 1; i <= m; i++)
        fin >> b[i];
}

void LCS()
{
    int i, j;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
    fout << lcs[n][m] << "\n";

    i = n;
    j = m;
    while(i > 0 && j > 0)
    {
        if (a[i] == b[j])
            { t[++k] = a[i]; i--; j--;}
        else if (lcs[i][j - 1] > lcs[i - 1][j]) j--;
                else i--;
    }

    for(i = k; i >= 1; i--)
        fout << t[i] << " ";
    fout << "\n";
}
int main()
{
    Citire();
    LCS();
    return 0;
}
