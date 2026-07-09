#include <bits/stdc++.h>

using namespace std;
int a[1025], b[1025];
int dp[1025][1025]; ///dp[i][j] = lungimea maxima a unui sir comun format din elementele lui A de la 1 la i si din B de la 1 la j
vector<int>rasp;
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int pozi=n, pozj=m;
    while(pozi>=1 && pozj>=1)
    {
        if(a[pozi]==b[pozj])
            rasp.push_back(a[pozi]), pozi--, pozj--;
        else
        {
            if(dp[pozi][pozj-1]>=dp[pozi-1][pozj])
                pozj--;
            else
                pozi--;
        }
    }
    reverse(rasp.begin(), rasp.end());
    cout<<rasp.size()<<'\n';
    for(int i=0; i<rasp.size(); i++)
        cout<<rasp[i]<<" ";
    return 0;
}
