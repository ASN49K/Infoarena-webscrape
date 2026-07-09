#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int t, n, a, xorsum;

int main()
{
    fin>>t;

    for(int p=1;p<=t;p++)
    {
        fin>>n;
        xorsum=0;
        for(int i=1;i<=n;i++)
        {
            fin>>a;
            xorsum=xorsum^a;
        }

        if(xorsum)
            fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    return 0;
}
