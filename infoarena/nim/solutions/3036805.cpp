#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t;
    fin >> t;

    while(t--)
    {
        int n;
        fin >> n;
        int xr = 0;
        for(int i=1 ; i<=n ; ++i)
        {
            int x;
            fin >> x;
            xr = xr^x;
        }
        if(xr)
            fout << "DA";
        else
            fout << "NU";
        fout << '\n';
    }
    return 0;
}
