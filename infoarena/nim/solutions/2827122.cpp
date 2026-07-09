#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

const int NMAX = 1e4 + 5;

int teste, n;
int v[NMAX];

int main()
{
    fin >> teste;
    for (int t = 1; t <= teste; ++t)
    {
        fin >> n;
        for (int i = 1; i <= n; ++i)
            fin >> v[i];

        int sum = v[1];
        for (int i = 2; i <= n; ++i)
            sum ^= v[i];

        if (sum == 0)
            fout << "NU\n";
        else
            fout << "DA\n";
    }
}
