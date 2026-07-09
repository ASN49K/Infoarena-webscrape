#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1024+5;

int n,m;
int a[N],b[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i=n;
    int j=m;
    vector<int>v;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            v.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]==dp[i][j])
                i--;
            else
                j--;
        }
    }
    cout<<v.size()<<"\n";
    reverse(v.begin(),v.end());
    for(auto &it:v)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}
/**

**/
