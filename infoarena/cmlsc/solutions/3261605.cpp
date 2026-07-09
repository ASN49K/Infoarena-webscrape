#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1025;
int N, M;
int a[N_MAX], b[N_MAX];
int dp[N_MAX][N_MAX];

void SetInput(string name)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    (void)!freopen((name + ".in").c_str(), "r", stdin);
    (void)!freopen((name + ".out").c_str(), "w", stdout);
}

void ReadVectors()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        cin >> a[i];

    for(int i = 1; i <= M; i++)
        cin >> b[i];
}

void Solve()
{
    stack<int> ans;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int i = N;
    int j = M;

    while(i >= 1 && j >= 1)
        if(dp[i][j] >= dp[i-1][j-1] + 1)
        {
            if(dp[i][j] > dp[i-1][j-1])
                ans.push(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }

    cout << dp[N][M] << '\n';
    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
}

int main()
{
    SetInput("cmlsc");

    ReadVectors();
    Solve();

    return 0;
}
