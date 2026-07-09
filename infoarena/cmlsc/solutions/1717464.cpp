#include <iostream>
#include <string>
#include<stdlib.h>
#include<fstream>
using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}

int a[257][257];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,v1[257],v2[257],nr=0,k=0,v[257];
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>v1[i];
    for(int j=1;j<=m;j++)
        f>>v2[j];
   for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
           {if(v1[i]==v2[j])
               a[i][j]=1+max(a[i-1][j],a[i][j-1]);
           else a[i][j]=max(a[i-1][j],a[i][j-1]);
           if(a[i][j]>nr)
               {
                   v[++k]=v1[i];
                   nr++;
               }
                }
  g<<a[n][m]<<endl;
       for(int i=1;i<=k;i++)
        g<<v[i]<<' '<<endl;
return 0;
}

