#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1025;
int n,m,a[N],b[N],d[N][N];
vector<int>sol;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n;i++)f>>a[i];
    for(int i=1; i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    while(d[n][m])
    {
        if(a[n]==b[m])
        {
            sol.push_back(a[n]);
            n--;
            m--;
        }
        else
            if(d[n-1][m]>=d[n][m-1])
                n--;
            else
                m--;
    }
    reverse(sol.begin(),sol.end());
    g<<sol.size()<<'\n';
    for(auto it:sol)
        g<<it<<' ';
    return 0;
}
