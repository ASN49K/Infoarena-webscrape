#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],poz[257],v[1025],lg[1025],t[1025],pre[1025];
int main()
{
    int n,m,i,x,k=0,j,maxx=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        {
            fin>>x;
            poz[x]=i;
        }
    for(i=1;i<=n;i++)
    {
         if(poz[a[i]]!=0)
         {
              lg[i]=1;
               for(j=1;j<i;j++)
               if(poz[a[i]]>poz[a[j]] &&  poz[a[j]]!=0 && lg[i]<(lg[j]+1))
               {
                    pre[i]=j;
                    lg[i]=lg[j]+1;
               }
               if(lg[i]>maxx)
                    {
                         maxx=lg[i];
                          t[lg[i]]=a[i];
                         j=i;
                         while(j>0)
                         {
                              t[lg[pre[j]]]=a[pre[j]];
                              j=pre[j];
                         }
                    }
         }
    }
     fout<<maxx<<'\n';
    for(i=1;i<=maxx;i++)
     fout<<t[i]<<" ";
    return 0;
}
