#include<iostream>
using namespace std;

const int NMAX = 1 << 10;

int dp[NMAX + 1][NMAX + 1];

int sus[NMAX + 1],jos[NMAX + 1];

pair<int,int> last[NMAX][NMAX];

void sol(int i,int j)
{
    if(!i || !j)
        return;

    pair<int,int> ant = last[i][j];
    if(ant.first == i - 1 && ant.second == j - 1)
        {
            sol(i - 1,j - 1);
            cout << sus[i] << " ";
        }

    else
        {
            sol(ant.first,ant.second);
        }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)
        {
            cin >> sus[i];
        }

    for(int j = 1; j <= m ; j++)
        {
            cin >> jos[j];
        }

    for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= m ; j++)
                {
                    if(sus[i] == jos[j])
                        {
                            dp[i][j] = 1 + dp[i - 1][j - 1];
                            last[i][j] = {i - 1,j - 1};
                        }

                    else
                        {
                            dp[i][j] = dp[i - 1][j];
                            last[i][j] = {i - 1,j};

                            if(dp[i][j] < dp[i][j - 1])
                                {
                                    dp[i][j] = dp[i][j - 1];
                                    last[i][j] = {i,j - 1};
                                }
                        }
                }
        }

    cout << dp[n][m] << '\n';
    sol(n,m);
}
