#include <bits/stdc++.h>

using namespace std;
int c[1024][1024];
int n,m,a[1025],b[1025],sol[1025],k;
ifstream input("cmlsc.in");
ofstream output("cmlsc.out");
int main()
{
    input>>n>>m;
    for(int i=1;i<=n;++i)
        input>>a[i];
    for(int j=1;j<=m;++j)
        input>>b[j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i] == b[j]) c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j],c[i][j-1]);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cout<<c[i][j]<<" ";
        cout<<'\n';
    }
    output<<c[n][m]<<'\n';
    int i=n,j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            sol[++k] = a[i];
            --i;
            --j;
        }
        else
            if(c[i-1][j] > c[i][j-1]) --i;
            else --j;
    }
    for(int i=k;k>=1;--k)
        output<<sol[k]<<" ";
    input.close();
    output.close();
    return 0;
}
