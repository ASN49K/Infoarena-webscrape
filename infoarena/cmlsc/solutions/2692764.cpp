#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m;
int v1[1100],v2[1100];
int dp[1100][1100];
vector <int> vec;
void DP()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
               {
                   dp[i][j]=1+dp[i-1][j-1];

               }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int main()
{
    fi>>n>>m;
    for(int i=1;i<=n;i++)
        fi>>v1[i];
    for(int i=1;i<=m;i++)
        fi>>v2[i];
    for(int i=0;i<=m;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    DP();
    fo<<dp[n][m]<<endl;
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            vec.push_back(v1[i]);
            i--;
            j--;
        }
    }
    for(int i=vec.size()-1;i>=0;i--)
        fo<<vec[i]<<" ";
    return 0;
}
