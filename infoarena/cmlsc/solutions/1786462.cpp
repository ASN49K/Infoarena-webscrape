#include <fstream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
//#include <unordered_map>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <bitset>
#include <map>
#define MAX 500000000000
//#include <iostream>
//#include <windows.h>
#include <deque>
using namespace std;
//ifstream cin("jocul.in");
//ofstream cout("jocul.out");
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[2026][2026], n, m, x[1045], y[1045];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1; i <= m; i++)
        cin >> y[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[n][m] << "\n";
    vector<int> sol;
    int i = n, j = m;
    while(i != 0 || j != 0)
    {
        if(dp[i][j] != dp[i][j - 1] && dp[i][j] != dp[i - 1][j])
        {
            sol.push_back(x[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }
    }
    for(int i = sol.size() - 1; i >= 0; i--)
        cout << sol[i] << " ";
    return 0;
}
