#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1025;
int n,m,a[N],b[N],d[N][N];
vector<int> sol;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=(a[i]==b[j])?(d[i-1][j-1]+1):max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<'\n';
    while(d[n][m])
    {
        if(a[n]==b[m])
        {
            sol.push_back(a[n]);
            n--;m--;
        }
        else
            if(d[n-1][m]>d[n][m-1])
                n--;
        else
            m--;
    }
    reverse(sol.begin(),sol.end());
    for(auto it:sol)
        g<<it<<' ';
    return 0;
}
