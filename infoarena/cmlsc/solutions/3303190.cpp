#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 1100

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n,m;
int a[NMAX+5],b[NMAX+5];
int dp[NMAX+5][NMAX+5];
vector<int> ans(0);

int main()
{
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
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
    i=n;
    j=m;
    while(i>0 && j>0)
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
    for(auto i : ans)
    {
        fout<<i<<" ";
    }
    return 0;
}
