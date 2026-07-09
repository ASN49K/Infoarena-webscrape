#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int n,m,vector1[1001],vector2[1001],dp[1001][1001],solutie[1001],k;
void build(int i,int j)
{
    if (!i || !j) return;
    if (vector1[i]==vector2[j])
    {
        build(i-1,j-1);
        solutie[++k]=vector1[i];
        //cout << vector1[i] << " ";
    }
    else
        if (dp[i-1][j]>dp[i][j-1]) build (i-1,j);
        else build(i,j-1);
}
int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> vector1[i];
    for (int i=1;i<=m;i++) cin >> vector2[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (vector1[i]==vector2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    //for (int i=1;i<=n;i++,cout << '\n')
      //  for (int j=1;j<=m;j++) cout << dp[i][j] << " ";
    //cout << dp[n][m] <<  '\n';
    build(n,m);
    cout << k << '\n';
    for (int i=1;i<=k;i++) cout << solutie[i] << " ";
    return 0;
}

