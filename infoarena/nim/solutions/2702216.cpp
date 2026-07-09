#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

int main()
{
    int x, ans;
    fin >> t;
    while(t--)
    {
        fin >> n;
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            fin >> x;
            ans = (ans^x);
        }
        fout << ((ans != 0 ) ? "DA\n" : "NU\n");
    }

    fin.close();
    fout.close();
    return 0;
}
