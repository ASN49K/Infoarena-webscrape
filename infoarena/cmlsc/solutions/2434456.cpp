#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int first, second;
int v[1400], b[1400];
short dp[1100][1100];

int main()
{
    int i, j, x, y;
    fin >> first >> second;
    for(i = 1; i <= first; i++)
        fin >> v[i];
    for(i = 1; i <= second; i++)
        fin >> b[i];
    for(i = 1; i <= first; i++)
    {

        for(j = 1; j <= second; j++)
        {
            if(v[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[first][second] << '\n';
    x = first;
    y = second;
    stack<int> sol;
    while(dp[x][y] != 0)
    {
        if(dp[x][y] == dp[x][y-1])
            y--;
        else if(dp[x][y] == dp[x-1][y])
            x--;
        else sol.push(v[x]), x--;
    }
    while(!sol.empty())
        fout << sol.top() << ' ', sol.pop();
    return 0;
}
