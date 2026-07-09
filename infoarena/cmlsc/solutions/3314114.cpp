#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int v[1030], u[1030];
int dp[1030][1030];

vector <int> rez;

int main()
{
    int n, m, x, y;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for(int j=1; j<=m; j++)
    {
        cin>>u[j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(u[j]==v[i])
                dp[i][j]=dp[i-1][j-1]+1;
            dp[i][j]=max(dp[i][j],max(dp[i-1][j], dp[i][j-1]));
        }
    }
    x=n;
    y=m;
    cout<<dp[n][m]<<'\n';
    while(x>=1 && y>=1)
    {
        if(v[x]==u[y])
        {
            if(dp[x-1][y-1]+1>dp[x-1][y] && dp[x-1][y-1]+1>dp[x][y-1])
            {
                rez.push_back(v[x]);
                x--;
                y--;
            }
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
                x--;
            else
                y--;
        }
    }
    for(int i=rez.size()-1; i>=0; i--)
    {
        cout<<rez[i]<<" ";
    }


    return 0;
}
