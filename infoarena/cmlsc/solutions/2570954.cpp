#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1030],b[1030],d[1030][1030],ans[1030],k;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int j=1;j<=m;j++) in>>b[j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    out<<d[n][m]<<'\n';
    int l=n,c=m;
    while(l>0&&c>0)
    {
        if(a[l]==b[c])
        {
            ans[++k]=a[l];
            l--;
            c--;
        }
        else if(d[l-1][c]>d[l][c-1]) l--;
        else c--;
    }
    for(int i=k;i>0;i--) out<<ans[i]<<" ";
    return 0;
}
