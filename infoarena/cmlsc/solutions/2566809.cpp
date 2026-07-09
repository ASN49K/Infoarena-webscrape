#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,a[1030],b[1030],d[1030][1030];

void solve(int p1,int p2,int lungime)
{
    if(lungime>0)
    {
        if(a[p1]==b[p2])
        {
            solve(p1-1,p2-1,lungime-1);
            g<<a[p1]<<" ";
        }
        else
        {
            if(d[p1-1][p2]==d[p1][p2])solve(p1-1,p2,lungime);
            else solve(p1,p2-1,lungime);
        }
    }
}

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)f>>a[i];
    for(i=1; i<=m; i++)f>>b[i];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }

    g<<d[n][m]<<'\n';

    solve(n,m,d[n][m]);
    return 0;
}
