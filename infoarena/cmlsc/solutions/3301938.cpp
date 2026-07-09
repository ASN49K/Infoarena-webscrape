#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 1100;
int a[NMAX + 5], b[NMAX + 5];
int dp[NMAX + 5][NMAX + 5];

string filename = "cmlsc";

ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    vector<int> ans;
    int i=n,j=m;
    while(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    fout<<ans.size()<<'\n';
    for(auto it : ans)
        fout<<it<<' ';
    return 0;
}
