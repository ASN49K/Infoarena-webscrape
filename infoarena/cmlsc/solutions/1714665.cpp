#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],fr[257],v[1025];
int main()
{
    int n,m,i,lg=0,pmax=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        {
            fin>>b[i];
            fr[b[i]]=i;
        }
    for(i=1;i<=n;i++)
    {
        if(fr[a[i]]!=0 && fr[a[i]]>pmax)
        {
            pmax=fr[a[i]];
            lg++;
            v[lg]=a[i];
        }
    }
    fout<<lg<<'\n';
    for(i=1;i<=lg;i++)
        fout<<v[i]<<" ";

    return 0;
}
