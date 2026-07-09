#include <iostream>
#include <fstream>
#include <vector>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

using namespace std;
int dp[1100][1100];
int s1[1100],s2[1100];
int n,m;
vector <int> v;
int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
    {
        in>>s1[i];
    }
    for(int i=1; i<=m; i++)
    {
        in>>s2[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                v.push_back(s1[i]);
            }
        }
    }
    out<<dp[n][m]<<"\n";
    for(auto e : v)
    {
        out<<e<<" ";
    }
    return 0;
}
