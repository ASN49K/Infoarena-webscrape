#include <bits/stdc++.h>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,i,j,a[1027],b[1027],c[1027][1027],d[1027],poz;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(a[j]==b[i])
                c[i][j]=1+c[i-1][j-1];
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[m][n]<<endl;
    while(n!=0&&m!=0)
    {
        if(a[n]==b[m])
        {
            d[++poz]=a[n];
            n--;
            m--;
        }
        else
        {
            if(c[m-1][n]>c[m][n-1])
                m--;
            else
                n--;
        }
    }
    for(;poz>0;poz--)
        g<<d[poz]<<" ";
    return 0;
}
