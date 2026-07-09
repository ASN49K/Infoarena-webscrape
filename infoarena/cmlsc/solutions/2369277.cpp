#include <iostream>
#include <fstream>
#include <stack>
#define NMAX 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, v1[NMAX],v2[NMAX],dp[NMAX][NMAX];
stack <int>st;
int main()
{
    f>>n>>m;
    int i, j;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(j=1;j<=m;j++)
        f>>v2[j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(v1[i]==v2[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    g<<dp[n][m]<<'\n';
    for(i=n,j=m;i>0 && j>0;)
    {
        if(v1[i]==v2[j]) st.push(v1[i]),--i,--j;
        else if(dp[i][j-1]>dp[i-1][j]) --j;
        else --i;
    }

    while(!st.empty())
    {
        g<<st.top()<<' ';
        st.pop();
    }
    return 0;
}
