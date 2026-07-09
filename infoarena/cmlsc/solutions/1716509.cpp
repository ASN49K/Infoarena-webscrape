#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],v[1025],lg[1025],fr[1025][256],cont[1025];
int main()
{
    int n,m,i,x,k=0,j,maxx=0,q,ok,t;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        {
            fin>>x;
            fr[0][x]++;
            fr[fr[0][x]][x]=i;
        }
    for(i=1;i<=n;i++)
        cont[a[i]]=1;
    for(i=1;i<=n;i++)
    {
         if(cont[a[i]]<=fr[0][a[i]])
         {
              lg[i]=1;
               for(j=1;j<i;j++)
                    if(fr[cont[a[i]]][a[i]]>fr[cont[a[j]]-1][a[j]] &&  fr[cont[a[j]]-1][a[j]]!=0 && lg[i]<(lg[j]+1))
               {
                    lg[i]=lg[j]+1;
               }
               if(lg[i]>maxx)
                    {
                         maxx=lg[i];
                    }
            cont[a[i]]++;
         }
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
