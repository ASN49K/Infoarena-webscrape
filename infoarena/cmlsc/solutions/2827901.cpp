#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N=1025;

int dp[N][N];

int a[N];
int b[N];

void sirul(int l,int c)
{
    if(l==0 || c==0)
    {
        return;
    }
    if(a[l]==b[c])
    {
        sirul(l-1,c-1);
        cout<<a[l]<<" ";
    }
    else if (dp[l-1][c] > dp[l][c-1])
    {
        sirul(l-1,c);
    }
    else
        sirul(l,c-1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            if(a[i] != b[j])
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[m][n]<<"\n";
    sirul(m,n);
    return 0;
}
