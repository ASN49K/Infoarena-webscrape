#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int dp[1028][1028],n,m,v[1028],w[1028];
vector <int > sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for (int i=1;i<=m;++i)
        scanf("%d",&w[i]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (v[i]==w[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][m]);
    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if (v[i]==w[j])
            {
                sol.push_back(v[i]);
                i--;j--;
            }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
        }
    }
    for (vector < int > :: reverse_iterator it = sol.rbegin();it!=sol.rend();++it)
        printf("%d ",*it);
    return 0;
}
