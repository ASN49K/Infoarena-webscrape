#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int maxn = 1030;
int dp[maxn][maxn];   /// dp[i][j] = cmlsc din primele i elemente ale lui A si primele j elemente ale lui B
vector <int> sol;
int A[maxn];
int B[maxn];
int main()
{
    int n, m;
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> A[i];
    for(int i = 1; i <= m; i++)
        in >> B[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    out << dp[n][m] << "\n";
    int x = n;
    int y = m;
    while(x > 0 && y > 0)
    {
        if(dp[x][y] == dp[x - 1][y - 1] + 1)
        {
            sol.push_back(A[x]);
            x--;
            y--;
        }
        else if(dp[x - 1][y] >= dp[x][y - 1])
            x--;
        else
            y--;
    }
    reverse(sol.begin(), sol.end());
    for(auto it : sol)
        out << it << " ";
    out << "\n";
    return 0;
}
