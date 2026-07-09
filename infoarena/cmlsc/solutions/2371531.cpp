#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],x[1025][1025];
int n,m;
void cmlsc()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
            x[i][j]=x[i-1][j-1]+1;
        else
            x[i][j]=max(x[i-1][j],x[i][j-1]);
    g<<x[n][m]<<"\n";
}
stack <int> y;
void sol()
{
    int i=n,j=m;
    while(x[i][j])
    {
        if(a[i]==b[j])
            y.push(a[i]),i--,j--;
        else
            if(x[i][j]==x[i-1][j])
            i--;
        else
            j--;
    }
}
void afis()
{
    while(!y.empty())
        g<<y.top()<<" ",y.pop();
}
int main()
{
    f>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    cmlsc();
    sol();
    afis();
    return 0;
}
