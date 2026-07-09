//#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025];
int a[1025], b[1025], ind=0;
int v[1025];
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<m; i++) cin>>b[i];
    //for (int i=1; i<=n; i++) dp[i][0]=0;
    //for (int j=1; j<=m; j++) dp[0][j]=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i-1]==b[j-1])
                {dp[i][j]=dp[i-1][j-1]+1; v[++ind]=b[j-1];}
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    //int i=n, j=m, ind=0;
    /*while (ind<dp[n][m])
    {
        if (a[i-1]==b[j-1])
        {
            v[++ind]=a[i-1];
            i--, j--;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else j++;
        }
    }*/
    for (int x=1; x<=ind; x++)
        cout<<v[x]<<' ';
    return 0;
}
