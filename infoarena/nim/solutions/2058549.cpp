#include <bits/stdc++.h>

using namespace std;

int t, n, a, xorsum;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");

    fin>>t;

    while(t--)
    {
        fin>>n;

        xorsum = 0;
        for(int i = 1; i <= n; ++i)
        {
            fin>>a;
            xorsum = xorsum ^ a;
        }

        if(xorsum)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }

    return 0;
}
