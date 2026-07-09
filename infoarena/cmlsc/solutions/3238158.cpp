#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1025], b[1025];
int dp[1025][1025];

void read_array(int *arr, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fin >> arr[i];
    }
}

int compute_lcs(int *a, int *b, int n, int m)
{
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

vector<int> generate_lcs(int *a, int *b, int n, int m, int dp[1025][1025])
{
    int i = n, j = m;
    vector<int> lcs;

    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            lcs.push_back(a[i]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    fin >> n >> m;
    read_array(a, n);
    read_array(b, m);
    fout << compute_lcs(a, b, n, m) << "\n";
    vector<int> lcs = generate_lcs(a, b, n, m, dp);
    for (int el : lcs)
    {   
        fout << el << " ";
    }
    return 0;
}