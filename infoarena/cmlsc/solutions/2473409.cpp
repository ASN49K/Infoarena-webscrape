#include <bits/stdc++.h>

using namespace std;
int c[1024][1024];
int n,m,a[1025],b[1025];
ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

void solve(int i,int j)
{
    if(i!=0 && j!=0)
        if(a[i] == b[j])
            {
               solve(i-1,j-1);
               output<<a[i]<<" ";
            }
        else
            if(c[i-1][j] > c[i][j-1])
                solve(i-1,j);
            else solve(i,j-1);
}
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
    solve(n,m);
    input.close();
    output.close();
    return 0;
}
