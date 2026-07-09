#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v1[1025],v2[1025],a[1025][1025],ans[1025];
int main()
{
    int n,m,i,j,k;
    in>>n>>m;
    for(i=1;i<=n;++i)
        in>>v1[i];
    for(j=1;j<=m;++j)
        in>>v2[j];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    out<<a[n][m]<<'\n';
    i=n;
    j=m;
    k=a[n][m];
    while(i>0 && j>0)
        if(v1[i]==v2[j]){
                ans[k--]=v1[i];
                --i;
                --j;
        }
            else
                if(a[i-1][j]>a[i][j-1])
                    --i;
                else
                    --j;
    for(i=1;i<=a[n][m];++i)
        out<<ans[i]<<" ";
    return 0;
}
