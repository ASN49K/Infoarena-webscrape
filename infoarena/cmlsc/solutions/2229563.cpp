#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int N = 1030;
int n,m,a[N],b[N],d[N][N];
void afisare(int,int);
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)fin>>a[i];
    for(int i=1;i<=m;i++)fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
void afisare(int i,int j)
{
    if(d[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        fout<<a[i]<<' ';
        return;
    }
    if(d[i-1][j]>d[i][j-1])
        afisare(i-1,j);
    else
        afisare(i,j-1);
}
