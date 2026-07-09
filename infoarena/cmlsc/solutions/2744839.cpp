#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int fn[257], fm[257];
int main()
{
    int n,m,i,x,L=0,l,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        fn[x]++;
    }
    for(i=1;i<=m;i++)
    {
        fin>>x;
        fm[x]++;
    }
    for(i=0;i<=257;i++)
        L+=min(fn[i],fm[i]);
    fout<<L<<"\n";
    for(i=0;i<=257;i++)
    {
        l=min(fn[i],fm[i]);
        for(j=1;j<=l;j++)
            fout<<i<<" ";
    }
    return 0;
}
