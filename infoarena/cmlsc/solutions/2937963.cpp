#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1025;

int n, m, a[N], b[N], dp[N][N];

void afisare(int l,int c)
{
    if (l==0 || c==0)
        return ;
    if (a[l]==b[c])
    {
        afisare(l-1,c-1);
        out<<a[l]<<" ";
    }
    else if (dp[l-1][c]>dp[l][c-1])
            afisare(l-1,c);
        else
            afisare(l,c-1);

}

int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=m; i++)
        in>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    out<<dp[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
