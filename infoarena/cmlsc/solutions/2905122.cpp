#include <bits/stdc++.h>

using namespace std;

#define NMAX 1026

ifstream f1("cmlsc.in");
ofstream f2("cmlsc.out");

int n, m;
int s1[NMAX], s2[NMAX];
int d[NMAX][NMAX];
int a[NMAX];
// d[i][j] - cel mai lung subsir comun pentru primele i elemente din s1 si primele j elemente din s2

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    f1 >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f1 >> s1[i];
    }
    for (int i = 1; i <= m; i++)
    {
        f1 >> s2[i];
    }

    int aux = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            if (s1[i] == s2[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
        }
    }


    f2 << d[n][m] << endl;

    int i = n;
    int j = m;
    int val = d[n][m];

    while (i > 0 && j > 0)
    {
        if (s1[i] == s2[j])
        {
            a[aux++] = s1[i];
            i--;
            j--;
        }
        else if (d[i][j - 1] > d[i - 1][j])
            j--;
        else
            i--;
    }

    for (int i = aux - 1; i >= 0; i--)
    {
        f2 << a[i] << ' ';
    }

    return 0;
}