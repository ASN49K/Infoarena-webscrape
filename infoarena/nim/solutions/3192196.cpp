#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");

ofstream fout("nim.out");
int n;
int x, y;
int t;
int main()
{
    fin >> t;
    while (t--)
    {
        fin >> n;
        fin >> x;

        for (int i = 2; i <= n; i++)
        {
            fin >> y;
            x ^= y;
        }
        if (x != 0)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
}