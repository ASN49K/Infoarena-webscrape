#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1029;
int a[NMAX],b[NMAX],dp[NMAX][NMAX];
int n,m;

void solve()
{
    int i,j;
    for(i=0; i<=n; ++i)
        dp[i][0] = 0;
    for(j=0; j<=m; ++j)
        dp[0][j] = 0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    fout << dp[n][m] << '\n';
    stack<int>st;
    while(n*m)
    {
        if(a[n] == b[m])
        {
            st.push(a[n]);
            --m;
            --n;
            continue;
        }
        if(dp[n][m] == dp[n-1][m])
            --n;
        else
            --m;
    }
    while(!st.empty())
    {
        fout << st.top() << ' ';
        st.pop();
    }
}

int main()
{
    int i;
    fin >> n >> m;
    for(i=1; i<=n; ++i)
        fin >> a[i];
    for(i=1; i<=m; ++i)
        fin >> b[i];
    solve();
    return 0;
}
