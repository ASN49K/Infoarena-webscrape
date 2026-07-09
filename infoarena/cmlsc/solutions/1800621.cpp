#include <bits/stdc++.h>
#define NMAX 1024
using namespace std;
ifstream fin("cmslc.in");
ofstream fout("cmslc.out");
int a[NMAX+1],b[NMAX+1],lis[NMAX+1][NMAX+1],n,m,sol[NMAX];
void Citire()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void Rezolvare()
{
    int i,j,nr,maxim=0;
    nr=0;
    ///lis[i][j]-lungimea subisirului comun maximal care incepe la pozitia i in a si la j in b
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
         if(a[i]==b[j])
          lis[i][j]=lis[i-1][j-1]+1;
    else lis[i][j]=max(lis[i-1][j],lis[i][j-1]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          maxim=max(maxim,lis[i][j]);
    fout<<maxim<<"\n";
    i=n;
    j=m;
    while(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            sol[++nr]=b[j];
            j--;
            i--;
        }
        else if(lis[i-1][j]<lis[i][j-1])
            j--;
        else i--;
    }
    for(i=nr;i>=1;i--)
        fout<<sol[i]<<" ";
}
int main()
{
    Citire();
    Rezolvare();
    return 0;
}
