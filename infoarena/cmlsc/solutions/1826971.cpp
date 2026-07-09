#include <bits/stdc++.h>
#define NMAX 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NMAX+1],b[NMAX+1],lis[NMAX+1][NMAX+1],n,m,sol[NMAX];
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void Rezolvare()
{
    int i,j,maxim,nsol;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
           lis[i][j]=lis[i-1][j-1]+1;
    else lis[i][j]=max(lis[i-1][j],lis[j][i-1]);
    maxim=nsol=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        maxim=max(maxim,lis[i][j]);
    fout<<maxim<<"\n";
    i=n;
    j=m;
      while(i && j)
    {
          if(a[i]==b[j])
        {
            sol[++nsol]=a[i];
            i--;
            j--;
        }
        else if(lis[i-1][j]>lis[i][j-1])
            i--;
        else
            j--;
    }
    for(i=nsol;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
}
int main()
{
    Citire();
    Rezolvare();
    return 0;
}
