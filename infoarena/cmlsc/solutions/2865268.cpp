#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int N[1030];
int M[1030];
int dp[1030][1030];
vector <int> ans;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fin >> N[i];
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> M[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (N[i]== M[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = n, j = m; i > 0; )
    {
        if (N[i] == M[j])
        {
            ans.push_back(N[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    fout << ans.size() << '\n';
    for (int x : ans)
    {
        fout << x << ' ';
    }
}
