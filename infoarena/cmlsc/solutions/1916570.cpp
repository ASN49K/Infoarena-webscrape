#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1030], w[1030],a[1030][1030],i,j,n,m;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v[i];
    for(i=1;i<=m;i++)
        fin>>w[i];

   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     if(v[i]==w[j])
      a[i][j]=1;

   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      a[i][j]+=max(a[i-1][j-1], max(a[i-1][j], a[i][j-1]));

   fout<<a[n][m]<<'\n';

   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
        {
         if(a[i][j]==a[i-1][j-1]+1 && a[i][j]==a[i][j-1]+1 && a[i][j]==a[i-1][j]+1)
            fout<<v[i]<<" ";
        }

    return 0;
}
