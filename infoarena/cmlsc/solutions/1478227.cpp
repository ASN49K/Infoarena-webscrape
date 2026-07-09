#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
/**
    dp[i][j] = cel mai lun subsir comun pentru sirul A[1, i] si B[1, j]


    dp[i][j] = dp[i-1][j], dp[i][j-1], dp[i-1][j-1]

    if(A[i] == B[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
    else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    dp[n][m];
*/

const int maxn = 1050;
int dp[maxn][maxn];
int A[maxn];
int B[maxn];

void reconstr(int i, int j) {
    if(i < 1 || j < 1)
        return ;
    if(A[i] == B[j]) {
        reconstr(i - 1, j - 1);
        out << A[i] << ' ';
    }
    else if(dp[i - 1][j] >= dp[i][j - 1])
        reconstr(i - 1, j);
    else
        reconstr(i, j - 1);
}

int main()
{
    int n, m;
    in >> m >> n;
    for(int i = 1; i <= m; i++)
        in >> A[i];
    for(int i = 1; i <= n; i++)
        in >> B[i];
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    /*vector <int> sol;
    out << dp[m][n] << '\n';
    int i = m;
    int j = n;
    while(i >= 1 && j >= 1) {
        if(A[i] == B[j]) {
            sol.push_back(A[i]);
            -- i;
            -- j;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1])
            -- i;
        else
            -- j;
    }
    reverse(sol.begin(), sol.end());
    for(auto it : sol)
        out << it << ' ';*/
    out << dp[m][n] << '\n';
    reconstr(m, n);
    return 0;
}
