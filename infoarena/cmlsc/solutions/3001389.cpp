//#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1e3 + 25;
int A[NMAX], B[NMAX], dp[NMAX][NMAX], n, m; 
pair<int, int> recon[NMAX][NMAX];
stack<int> af;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> B[j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m ; j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                recon[i][j] = {i - 1, j - 1};
            }
            else
            {
                //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    recon[i][j] = {i - 1, j};
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    recon[i][j] = {i, j - 1};
                }
                
            }
        }
    }
    cout << dp[n][m] << '\n';
    int istart = recon[n][m].first, jstart = recon[n][m].second, i_cop;
    while (istart != 0 || jstart != 0)
    {
        if (A[istart + 1] == B[jstart + 1])
        {
            af.push(A[istart + 1]);
        }
        i_cop = istart;
        istart = recon[istart][jstart].first, jstart = recon[i_cop][jstart].second;
    }
    
    while (!af.empty())
    {
        cout << af.top() << ' ';
        af.pop();
    }
    
}