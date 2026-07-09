#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],poz[257],v[1025],lg[1025],t[1025],pre[1025],fr[1025][256];
int main()
{
    int n,m,i,x,k=0,j,maxx=0,q;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        {
            fin>>x;
            fr[0][x]++;
            fr[fr[0][x]][x]=i;
        }
    for(i=1;i<=256;i++)
        fr[0][i]=1;
    for(i=1;i<=n;i++)
    {
         if(fr[fr[0][a[i]]][a[i]]!=0)
         {
              lg[i]=1;
               for(j=1;j<i;j++)
                for(q=1;q<fr[0][a[j]];q++)
               if(fr[fr[0][a[i]]][a[i]]>fr[q][a[j]] &&  fr[q][a[j]]!=0 && lg[i]<(lg[j]+1))
               {
                    lg[i]=lg[j]+1;
               }
               if(lg[i]>maxx)
                    {
                         maxx=lg[i];
                    }
            fr[0][a[i]]++;
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
