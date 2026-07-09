#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m;
int a[1030],b[1030],d[1030][1030];
void afisare(int l,int c)
{
    if(l==0||c==0) return;
    if(a[l]==b[c])
    {
        afisare(l-1,c-1);
        out<<a[l]<<" ";
    }
    else
    {
        if(d[l-1][c]>d[l][c-1]) afisare(l-1,c);
        else afisare(l,c-1);
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int i=1;i<=m;i++) in>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    out<<d[n][m]<<'\n';

    afisare(n,m);
    return 0;
}
