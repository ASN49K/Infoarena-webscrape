#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[1030][1030],n,m,x[1030],a[1030],sol[1030],k;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>x[i];
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==a[j])mat[i][j]=mat[i-1][j-1]+1;
                else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    g<<mat[n][m];
    for(int i=n,j=m;j&&i;)
        if(x[i]==a[j]){sol[++k]=x[i];i--;j--;}
            else if(mat[i-1][j]<mat[i][j-1])j--;
                    else i--;
    g<<'\n';
    for(int i=k;i>=1;i--)
        g<<sol[i]<<' ';
    f.close();
    g.close();
    return 0;
}
