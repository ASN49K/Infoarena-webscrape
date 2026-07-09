#include <iostream>
#include <fstream>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");
int n, m;
int a[1025], b[1025];
int dp[1025][1025], dir[1025][1025];

void print(int i, int j)
{
    if(!i || !j)
        return;
    if(dir[i][j] == 1)
    {
        print(i - 1, j - 1);
        out<<a[i]<<' ';
    }
    else if(dir[i][j] == 2)
        print(i - 1, j);
    else
        print(i, j - 1);
}

int main()
{
    in>>n;
    in>>m;
    for(int i = 1;i <= n;i++)
        in>>a[i];
    for(int i = 1;i <= m;i++)
        in>>b[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 1;
            }
            else
            {
                int mx = dp[i - 1][j];
                int d = 2;
                if(mx < dp[i][j - 1])
                {
                    mx = dp[i][j - 1];
                    d = 3;
                }
                dp[i][j] = mx;
                dir[i][j] = d;
            }
        }
    }
    out<<dp[n][m]<<'\n';
    print(n, m);
    return 0;
}