#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int A[1025], B[1025], dp[1025][1025], rez[1024];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
    {
        cin>>A[i];
    }
    for(int i = 1; i <= m; ++i)
    {
        cin>>B[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {

            if(A[i] == B[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }
    cout<<dp[n][m]<<"\n";
    int i = n, j = m;
    while(i >= 1 && j >= 1 && dp[i][j] > 0)
    {
        if(A[i] == B[j])
        {
            rez[dp[i][j]] = A[i];
            --i;
            --j;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    for(int i = 1; i <= dp[n][m]; ++i)
    {
        cout<<rez[i]<<" ";
    }
    return 0;
}

