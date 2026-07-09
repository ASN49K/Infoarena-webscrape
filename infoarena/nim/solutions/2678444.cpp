#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int n, i, t, val, sol;
    sol = 0;
    fin >> t;
    for(i = 1; i <= t; ++i)
    {
        sol = 0;
        fin >> n;
        for(int j = 1; j <= n; ++j)
        {
            fin >> val;
            sol = sol ^ val;
        }

        if(sol == 0)
            fout << "NU\n";
        else fout << "DA\n";
    }


    return 0;
}
