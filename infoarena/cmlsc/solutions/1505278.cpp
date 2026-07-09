#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[2015],b[2015],dp[1050][1050],k;
int sol[2015];

void Read()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
}



void LCS()
{
    int i,j,v;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
    k = v = dp[n][m];
    fout<<k<<"\n";
    for(i=n, j=m; i;)
    {
        if(a[i]==b[j]) {sol[k--] = a[i]; i--;j--;}
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    for(i=1;i<=v;i++) fout<<sol[i]<<" ";


}


int main()
{
    Read();
    LCS();
    fout.close();
    return 0;
}
