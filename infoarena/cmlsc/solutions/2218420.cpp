#include <fstream>
#include <algorithm>
#define NMAX 1025
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[NMAX],b[NMAX],dp[NMAX][NMAX];
void reconst(int x,int y)
{
    if(x==0)
    return;
    if(a[x]==b[y])
    {
        reconst(x-1,y-1);
        cout<<a[x]<<" ";
    }
    else
        if(dp[x][y-1]>dp[x-1][y])
            reconst(x,y-1);
        else
            reconst(x-1,y);
}
int main()
{

    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<endl;
    reconst(n,m);
    return 0;
}
