#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int n,i,j,m,x,s;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>m;
        s=0;
        for(j=1;j<=m;j++)
        {
            fin>>x;
            s=s^x;
        }
        if(s==0)
            fout<<"NU"<<'\n';
        else
            fout<<"DA"<<'\n';
    }
    return 0;
}
