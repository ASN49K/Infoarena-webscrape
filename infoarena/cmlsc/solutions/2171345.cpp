#include <bits/stdc++.h>
#define NMax 1050
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[NMax], b[NMax], lcs[NMax][NMax];
int n, m;

inline void Citire()
{
    int i;

    fin >> n >> m;

    for(i = 1; i <= n; i++)
        fin >> a[i];

    for(i = 1; i <= m; i++)
        fin >> b[i];
}

inline void Rezolva()
{
    int i, j;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);

    fout << lcs[n][m] << "\n";
}

void Afisare(int i, int j)
{
    if(i < 1 && j < 1)
        return;
    else
        if(a[i] == b[j])
        {
            Afisare(i - 1, j - 1);
            fout << a[i] << " ";
        }
        else if (lcs[i][j - 1] > lcs[i - 1][j]) Afisare(i, j - 1);
                else Afisare(i - 1, j);
}

int main()
{
    Citire();
    Rezolva();
    Afisare(n, m);
    return 0;
}
