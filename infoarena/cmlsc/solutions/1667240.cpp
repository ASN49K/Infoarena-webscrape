#include <iostream>
#include<fstream>
#define maxn 1100
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[maxn], b[maxn], dp[maxn][maxn], sol[maxn];
int i, j, cnt, n, m;

int main()
{

    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
    while(n>0&&m>0)
    {
        if(a[n]==b[m])
        {
            sol[cnt++]=a[n];
            n--;
            m--;
        }
        else if(dp[n-1][m] > dp[n][m-1])
            n--;
        else m--;
    }
    fout<<cnt<<'\n';
    for(i=cnt-1;i>=0;i--)
        fout<<sol[i]<<" ";

    return 0;
}
