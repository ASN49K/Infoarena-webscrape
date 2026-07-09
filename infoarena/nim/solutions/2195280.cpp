#include <bits/stdc++.h>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,x;
int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>n;
        long long xr=0;
        for(int j=1;j<=n;j++)
        {
            fin>>x;
            xr^=x;
        }
        if(xr)
            fout<<"DA";
        else
            fout<<"NU";
        fout<<"\n";
    }
    return 0;
}
