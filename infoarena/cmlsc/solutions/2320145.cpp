#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

using namespace std;
int dp[1100][1100];
int s1[1100],s2[1100];
int n,m;
vector < int > v;
void traceback(int x , int y)
{
    if(x==0 || y==0)
    {
        return;
    }
    if(s1[x]==s2[y])
    {
        v.push_back(s1[x]);
        traceback(x-1,y-1);
    }
    else
    {
        if(dp[x][y-1]>dp[x-1][y])
        {
            traceback(x,y-1);
        }
        else
        {
            traceback(x-1,y);
        }
    }
}
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
            }
        }
    }
    out<<dp[n][m]<<"\n";
    traceback(n,m);
    reverse(v.begin(),v.end());;
    for(auto e : v)
    {
        out<<e<<" ";
    }
    return 0;
}
