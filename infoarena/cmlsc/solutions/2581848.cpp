#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
#define NMAX 1026
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
int v1[NMAX], v2[NMAX], p_dinamica[NMAX][NMAX], vect_poz[NMAX];
int max_nuber;
void Read()
{
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        in >> v1[i];
    for (int i = 1; i <= m; i++)
        in >> v2[i];
}

void Programare_Dinamica()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v1[i] == v2[j])
                p_dinamica[i][j] = 1 + p_dinamica[i - 1][j - 1];
            else
            {
                p_dinamica[i][j] = max(p_dinamica[i - 1][j - 1], p_dinamica[i][j - 1]);
            }
        }
    }
}

void Write()
{
    int k = 0;
    for (int i = n, j = m; i;)
    {
        if (v1[i] == v2[j])
            vect_poz[++k] = v1[i], i--, j--;
        else if (p_dinamica[i - 1][j] < p_dinamica[i][j - 1])
            j--;
        else
        {
            i--;
        }
    }
    out << k << '\n';
    for (int i = k; i >= 1; i--)
        out << vect_poz[i] << " ";
}

int main()
{
    Read();
    Programare_Dinamica();
    Write();
    return 0;
}
