#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int d[1024][1024],a[1024],b[1024],v[1024],n,m,c;

void LCS(int i,int j)
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    for(i=n;j=m;i)
    {
        if(a[i]==b[j])
        {
            v[++c]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
            --j;
            else
            --i;
    }
}

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
    LCS(1,1);
    out<<c<<'\n';
    for(int i=c;i>=1;i--)
        out<<v[i]<<" ";

}
