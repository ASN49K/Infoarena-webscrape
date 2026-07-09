#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int d[1030][1030],n,m,ans[1030],a[1030],b[1030],k;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int i=1;i<=m;i++) in>>b[i];
    int i=1,j=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
         if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
         else d[i][j]=max(d[i-1][j],d[i][j-1]);
    out<<d[n][m]<<'\n';
    i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            ans[++k]=a[i];
            i--,j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1]) i--;
            else j--;
        }
    }
    for(int i=k;i>0;i--) out<<ans[i]<<" ";
    return 0;
}
