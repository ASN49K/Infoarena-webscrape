#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1030],b[1030],mat[1030][1030],m,n;

void cmls()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
        }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<mat[i][j]<<' ';
        cout<<'\n';
    }*/
}

void citire()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
        f>>a[i];
    for(int i=1; i<=m; ++i)
        f>>b[i];
}

void afis()
{
    g<<mat[n][m]<<'\n';
    for(int i=0;i<m;i++)
        if(mat[n][i]!=mat[n][i+1])
            g<<a[i+1]<<' ';
}

int main()
{
    citire();
    cmls();
    afis();
    return 0;
}
