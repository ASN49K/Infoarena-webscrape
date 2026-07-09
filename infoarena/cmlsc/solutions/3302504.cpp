#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string filename = "cmlsc";

ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

const int NMAX = 1024;

int dp[NMAX + 5][NMAX + 5];
int a[NMAX + 5],b[NMAX + 5];

int main()
{
    int n, m;
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
                dp[i][j] = dp[i - 1][j - 1]+1;
            else
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }


    vector<int> ans;
    int currentI = n;
    int currentJ = m;

    while(currentI and currentJ)
    {
        if(a[currentI] == b[currentJ])
        {
            ans.push_back(a[currentI]);
            currentI--;
            currentJ--;
        }
        else if(dp[currentI - 1][currentJ] > dp[currentI][currentJ - 1])
        {
            currentI--;
        }
        else
        {
            currentJ--;
        }
    }
    fout<<ans.size()<<'\n';
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        fout<< it<<' ';

    return 0;
}
