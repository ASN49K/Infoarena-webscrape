#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    vector<int> a(n+1);
    vector<int> b(m+1);

    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        fin >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));



    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
        }

    fout << dp[n][m] << endl;

    vector<int> lcs;
    int i = n, j = m;
    while (i>0 && j>0)
    {
        if (a[i] == b[j])
        {
            lcs.push_back(a[i]);
            --i;
            --j;
        }
        else
            if (dp[i-1][j] >= dp[i][j-1])
                --i;
            else
                --j;
    }
    for (int i = lcs.size() - 1; i >= 0; --i)
    {
        fout << lcs[i] << " ";
    }
    
}