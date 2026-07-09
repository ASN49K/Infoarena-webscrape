#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

void solve ()
{
    int n;
    fin >> n;
    int rez=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        fin >> x;
        rez^=x;
    }
    if (rez)
        fout << "DA" << '\n';
    else
        fout << "NU" << '\n';
}

signed main()
{
    int t;
    fin >> t;
    for (int i=1; i<=t; i++)
        solve();
    return 0;
}
