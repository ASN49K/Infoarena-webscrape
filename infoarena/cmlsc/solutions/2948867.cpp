#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using ll = long long;

using namespace std;

const int NMAX = 1e3 + 5;
/*******************************/
// INPUT / OUTPUT

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
/*******************************/
/// GLOBAL DECLARATIONS

int N, M;
short a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
vector <short> sol;
/*******************************/
/// FUNCTIONS

void ReadInput();
void Solution();
void Output();
/*******************************/
///-------------------------------------
inline void ReadInput()
{
    f >> N >> M;

    for (int i = 1 ; i <= N ; ++ i) f >> a[i];
    for (int i = 1 ; i <= M ; ++ i) f >> b[i];
}
///-------------------------------------
inline void recur(const int &i, const int &j)
{
    if (i == 0 || j == 0) return;
    
    if (a[i] == b[j])
    {
        recur(i - 1, j - 1);
        sol.push_back(a[i]);
        return;
    }

    if (dp[i - 1][j] > dp[i][j - 1])
        recur(i - 1, j);
    else
        recur(i, j - 1);
}
///-------------------------------------
inline void Solution()
{
    for (int i = 1 ; i <= N ; ++ i)
    {
        for (int j = 1 ; j <= M ; ++ j)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    recur(N, M);
}
///-------------------------------------
inline void Output()
{
    g << dp[N][M] << "\n";
    for (auto x: sol)
        g << x << " ";
}
///-------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ReadInput();
    Solution();
    Output();
    return 0;
}
