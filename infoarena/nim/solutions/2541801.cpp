#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, s;

int main()
{
    fin >> t;
    while (t--)
    {
        int n;
        fin >> n;

        for (int i = 1; i <= n; i++)
        {
            int x;
            fin >> x;

            s ^= x;
        }

        if (s)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return 0;
}
