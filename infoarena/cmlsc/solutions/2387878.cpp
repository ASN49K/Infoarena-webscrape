#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int m,n;
int a[1050], b[1050], dp[1030][1030];
vector<int> sol;

int main()
{
    in>>m>>n;
    for (int i = 1; i <= m; ++i) in>>a[i];
    for (int i = 1; i <= n; ++i) in>>b[i];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    for (int i = m, j = n; i;)
    {
        if (a[i] == b[j])
        {
            sol.push_back(a[i]);
            --i;
            --j;

        }
        else if (dp[i - 1][j] < dp[i][j - 1]) --j;
        else --i;
    }
    out<<sol.size()<<"\n";
    for (vector<int> :: reverse_iterator it = sol.rbegin(); it != sol.rend(); ++it) out<<*it<<" ";
    return 0;
}
