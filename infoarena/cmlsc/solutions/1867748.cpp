#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short a[1027],b[1027],n,m,k;
short c[1027][1027];
short sir[1027];
void Citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];
}
void Rezolvare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    fout<<c[n][m]<<"\n";
    for(int i=n,j=m; i>=1;)
    {
        if(a[i]==b[j])
            sir[++k]=a[i],i--,j--;
        else if(c[i-1][j]<c[i][j-1]) j--;
        else i--;
    }
    for(int i=k;i>=1;i--)
        fout<<sir[i]<<" ";
    fout<<"\n";
}
int main()
{
    Citire();
    Rezolvare();
    return 0;
}
