#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],fr[257],v[1025],lg[1025];
int main()
{
    int n,m,i,x,k=0,j,maxx=0,maxim;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        {
            fin>>x;
            fr[x]=i;
        }
    for(i=1;i<=n;i++)
    {
         maxim=0;
        for(j=1;j<i;j++)
        if(fr[a[i]]>fr[a[j]] && lg[j]>maxim)
        {
            maxim=lg[j];
        }
        if(fr[a[i]]!=0)
        lg[i]=maxim+1;
        if(lg[i]>maxx)
            maxx=lg[i];
    }

     fout<<maxx<<'\n';
    for(i=n;i>=1;i--)
    {
        if(lg[i]==maxx && maxx!=0)
        {
            v[++k]=a[i];
            maxx--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<v[i]<<" ";

    return 0;
}
