#include <bits/stdc++.h>

using namespace std;

int a[1025],b[1025],dp[1025][1025];
int al,bl;

vector <int> sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    cin>>al>>bl;

    for(int i=1;i<=al;i++)
        cin>>a[i];

    for(int i=1;i<=bl;i++)
        cin>>b[i];

    for(int i=1;i<=al;i++)
        for(int j=1;j<=bl;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    cout<<dp[al][bl]<<'\n';

    int i=al,j=bl;
    while(i>=1 && j>=1)
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }

    for(int i=sol.size()-1;i>=0;i--)
        cout<<sol[i]<<' ';
}
