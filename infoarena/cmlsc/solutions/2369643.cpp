#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, k;
int x[1025], y[1025], rez[1025];
int d[1025][1025];

void afis(int i, int j)
{
    if(i==0 || j==0) return;
    if(x[i]==y[j])
    {
        afis(i-1, j-1);
        fout<<x[i]<<" ";
    }
    else if(d[i-1][j]>d[i][j-1]) afis(i-1, j);
    else afis(i, j-1);
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i) fin>>x[i];
    for(int j=1; j<=m; ++j) fin>>y[j];
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(x[i]==y[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }
    fout<<d[n][m]<<"\n";
    int i=n, j=m;
    /*while(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            rez[++k]=x[i];
            --i;
        }
        else if(d[i-1][j]>d[i][j-1]) --i;
        else --j;
    }*/
    afis(n, m);
    fout<<"\n";
    /*for(int i=k; i>=1; --i) fout<<rez[i]<<" ";
    fout<<"\n";*/
    return 0;
}
