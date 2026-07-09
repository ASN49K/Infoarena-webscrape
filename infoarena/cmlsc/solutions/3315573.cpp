#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1030],b[1030],dp[1030][1030];
int dir[1030][1030];
stack<int>ans;

int main()
{
    fin >>m >>n;
    for(int i = 1;i <= m;i++)
    {
        fin >>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        fin >>b[i];
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                dir[i][j] = 2;

            }
            else
            {
               if(dp[i][j-1] >= dp[i-1][j])
               {
                   dp[i][j] = dp[i][j-1];
                   dir[i][j] = 1;
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
                   dir[i][j] = 3;
               }
            }
        }
    }
    fout <<dp[m][n]<<"\n";
    int x = m;
    int y = n;
    while(dir[x][y] != 0)
    {
        if(dir[x][y] == 1)
        {
            y--;
        }
        else if(dir[x][y] == 3)
        {
            x--;
        }
        else
        {
            ans.push(a[x]);
            x--;
            y--;
        }
    }
    while(!ans.empty())
    {
        fout <<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}
