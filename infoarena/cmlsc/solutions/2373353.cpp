#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int n,m,i,j,a[1100],b[1100],d[1100][1100];


void reconstituire(int p1,int p2,int val)
{

    if(val>=1)
    {
        if(a[p1]==b[p2])reconstituire(p1-1,p2-1,val-1);
        else
        {
            if(d[p1-1][p2]>d[p1][p2-1])reconstituire(p1-1,p2,val);
            else reconstituire(p1,p2-1,val);
        }

    if(a[p1]==b[p2])g<<a[p1]<<" ";
    }
}


int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    g<<d[n][m]<<'\n';
    reconstituire(n,m,d[n][m]);



    return 0;
}
