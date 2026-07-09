#include <fstream>
#include <vector>
#include <algorithm >

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v[1025], v2[1025];
int dp[1025][1025];
vector<int>rasp;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>v[i];
    for(int i=1; i<=m; i++)
        cin>>v2[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    int pozx=n, pozy=m;
    while(pozx>0 && pozy>0)
    {
        if(dp[pozx][pozy]==dp[pozx-1][pozy-1]+1)
            rasp.push_back(v[pozx]), pozx--, pozy--;
        else
            pozx--;
    }
    reverse(rasp.begin(), rasp.end());
    for(int i=0; i<rasp.size(); i++)
        cout<<rasp[i]<<" ";
    return 0;
}
