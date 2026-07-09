#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

using namespace std;


using VI = vector<int>;
using VPI = vector<pair<int, int>>;
using VVPI = vector<VPI>;

int n1, n2;
VVPI dp;

int main()
{
    fin >> n1 >> n2;
    VI v1(n1 + 1), v2(n2 + 1);

    for (int i = 1; i <= n1; ++i)
        fin >> v1[i];

    for (int i = 1; i <= n2; ++i)
        fin >> v2[i];

    dp = VVPI(n1 + 1, VPI(n2 + 1));

    for (int i = 1; i <= n1; ++i)
        for (int j = 1; j <= n2; ++j)
        {
            if (v1[i] == v2[j])
            {
                dp[i][j].first = dp[i - 1][j - 1].first + 1;
                dp[i][j].second = (i - 2) * n2 + (j - 2);
                if (i - 2 == -1 || j - 2 == -1)
                    dp[i][j].second = -1;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j].first = dp[i - 1][j].first;
                    dp[i][j].second = (i - 2) * n2 + (j - 1);
                    if (i - 2 == -1)
                        dp[i][j].second = -1;
                }
                else
                {
                    dp[i][j].first = dp[i][j - 1].first;
                    dp[i][j].second = (i - 1) * n2 + (j - 2);
                    if (j - 2 == -1)
                        dp[i][j].second = -1;
                }
            }
        }


    VI result;

    int last = (n1 - 1) * n2 + n2 - 1;


    while (last / n2 + 1 > 0 && last % n2 + 1 > 0)
    {
        if (v1[last / n2 + 1] == v2[last % n2 + 1])
            result.emplace_back(v1[last / n2 + 1]);

        last = dp[last / n2 + 1][last % n2 + 1].second;

    }

    reverse(result.begin(), result.end());

    fout << dp[n1][n2].first << '\n';
    for (auto i : result)
        fout << i << ' ';
}
