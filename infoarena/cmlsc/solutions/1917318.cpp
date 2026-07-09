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
//#include "PEZai.h"
//#include <Tlhelp32.h>
using namespace std;
ifstream cin("jocul.in");
ofstream cout("jocul.out");
//ifstream cin("cmlsc.in");
//ofstream cout("cmlsc.out");
using namespace std;
int x[1054], y[1056], n, m, dp[1053][1045];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1; i <= m; i++)
        cin >> y[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    int ii = n, jj = m;
    vector<int> sol;
    while (ii > 1)
    {
        if(x[ii] == y[jj] && dp[ii][jj] - 1 == dp[ii - 1][jj - 1]){
            sol.push_back(x[ii]);
            ii--;
            jj--;
        }
        else
            if(dp[ii - 1][jj] > dp[ii][jj - 1])
            {
                ii--;
            }
            else
                jj--;
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    cout << dp[n][m] << "\n";
    for(int i = sol.size() - 1; i >= 0; i--)
        cout << sol[i] << " ";
}
