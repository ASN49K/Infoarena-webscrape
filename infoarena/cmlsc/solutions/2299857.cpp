#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,maxx1,maxx2,fv1[260],fv2[260],x,nr,i,j,k;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        fv1[x]++;
        if(x>maxx1)
            maxx1=x;
    }
    for(i=1; i<=m; i++)
    {
        fin>>x;
        fv2[x]++;
        if(x>maxx2)
            maxx2=x;
    }
    k=min(maxx1,maxx2);
    for(i=1; i<=k; i++)
        if(fv1[i]>0 && fv2[i]>0)
            nr++;
    fout<<nr<<'\n';
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=min(fv1[i],fv2[i]); j++)
            fout<<i<<" ";
    }
    return 0;
}
