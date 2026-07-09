#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <map>
#define pb push_back
#define mp make_pair
#define INF numeric_limits<int>::max()
#define bit(x) (-x)&x
#define int64 long long
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],n,m,dp[1025][1025];
void abc(int x,int y)
{
    if(x==0 || y==0)return;
    if(a[x]==b[y])
    {
        abc(x-1,y-1);
        out<<a[x]<<' ';
    }
    else if(dp[x][y]==dp[x-1][y])
        abc(x-1,y);
    else
        abc(x,y-1);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
    else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    out<<dp[n][m]<<'\n';
    abc(n,m);
    return 0;
}

