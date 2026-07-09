#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int maxN = 1025;

int dp[maxN][maxN];
int a[maxN], b[maxN];

int main()
{
    int n, m; fin >> n >> m;

    for(int i = 1; i <= n; ++i)
        fin >> a[i];

    for(int j = 1; j <= m; ++j)
        fin >> b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            if(a[i] != b[j])
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }

    fout << dp[n][m] << "\n";

    vector <int> ans;
    int i = n, j = m;
    while(i != 0 && j != 0)
    {
        if(dp[i][j] == dp[i-1][j-1] + 1) {
            ans.push_back(a[i]);
            i--; j--;
        } else if(dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }

    vector <int> :: reverse_iterator it;
    for(it = ans.rbegin(); it != ans.rend(); it++)
        fout << *it << " ";

    return 0;
}
