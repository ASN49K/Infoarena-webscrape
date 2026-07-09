#include <bits/stdc++.h>
#define D 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v[D][D],a[D],b[D],sol[D];

int main()
{
    int m,n,i,j,l,c;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i][j-1],v[i-1][j]);
    g<<v[m][n]<<"\n";
    int lastc=n,mx=v[m][n];
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }*/
    for(l=m;l>=1;l--)
        for(c=lastc;c>=1;c--)
            if(v[l][c]==mx && a[l]==b[c])
            {
                sol[mx]=a[l];
                mx--;
                lastc=c;
            }
    for(i=1;i<=v[m][n];i++)
        g<<sol[i]<<" ";
}
