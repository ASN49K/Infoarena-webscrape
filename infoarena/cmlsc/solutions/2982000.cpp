#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,x,k,a[1025],b[1025],d[1025][1025],v[1025];

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
    {
        f>>x;
        a[i]=x;
    }
    for(j=1; j<=m; j++)
    {
        f>>x;
        b[j]=x;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
//    cout<<0<<' '<<0<<' ';
//    for(i=1; i<=m; i++)
//    {
//        cout<<b[i]<<' ';
//    }
//    cout<<'\n';
//    for(i=0; i<=n; i++)
//    {
//        cout<<a[i]<<' ';
//        for(j=0; j<=m; j++)
//        {
//            cout<<d[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    i=n;
    j=m;
    k=d[n][m];
    g<<k<<'\n';
    while(i>=1 and j>=1)
    {
        if(d[i][j]==d[i-1][j])
        {
            i--;
        }
        else
        {
            if(d[i][j]==d[i][j-1])
            {
                j--;
            }
            else
            {
                v[k--]=a[i];
                i--;
                j--;
            }
        }
    }
    for(i=1; i<=d[n][m]; i++)
    {
        g<<v[i]<<' ';
    }
    return 0;
}
