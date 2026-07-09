#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short n, m, a[2000], b[2000], dp[2000][2000], sol[2000], k;

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);

    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    fout<<dp[n][m]<<'\n';

    int i=n, j=m;

    while(i>=1 && j>=1)
        if(a[i]==b[j])
        sol[++k]=a[i], i--, j--;
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else i--;

    for(int i=k; i>=1; i--)
        fout<<sol[i]<<' ';


    fin.close();
    fout.close();
    return 0;
}
