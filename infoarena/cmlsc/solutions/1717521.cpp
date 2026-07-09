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

int a[1100][1100];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,v1[1100],v2[1100],nr=0,k=0,v[1100];
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>v1[i];
    for(int j=1;j<=m;j++)
        f>>v2[j];
   for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++)
           if(v2[i]==v1[j])
               a[i][j]=1+a[i-1][j-1];
           else a[i][j]=max(a[i-1][j],a[i][j-1]);

  g<<a[n][m]<<endl;
       for(int i=1;i<=m;i++)
        if(a[n][i]!=a[n][i-1])
        g<<v1[i]<<' ';
f.close();
g.close();
return 0;
}

