#include<bits/stdc++.h>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1026], b[1026], t[1026][1026], rez[1026];
int n, m, k; // linii, coloane

void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) fin >> a[i];
    for (int i = 1; i <= m; ++i) fin >> b[i];
}

void dinamica()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) t[i][j] = 1 + t[i-1][j-1];
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
}

void parcurgere()
{
    int i = n, j = m;
    fout<<t[n][m]<<'\n';
    while (t[i][j])
    {
        if (a[i] == b[j])
        {
            rez[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if (t[i-1][j] > t[i][j-1]) --i;
            else --j;
        }
    }

    for (; k >= 1; --k) fout << rez[k] << ' ';
}

int main()
{
    citire();
    dinamica();
    parcurgere();
    fout.close();
    return 0;
}
