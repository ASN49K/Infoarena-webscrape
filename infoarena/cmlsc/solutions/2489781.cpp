#include <fstream>
#include <cstring>
#include <stack>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long long n,m,i,j,dp[1025][1025],l,c;
long long a[1025],b[1025];
stack <long long> st;
int main()
{
    f>>n>>m;
    for(i=0;i<n;i++)
        f>>a[i];
    for(i=0;i<=m;i++)
        f>>b[i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i]==b[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    l=dp[n][m];
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
            if(dp[i][j]==l && a[i-1]==b[j-1])
            {
                l--;
                st.push(a[i-1]);
            }
        }
    g<<dp[n][m]<<'\n';
    while(!st.empty())
    {
        g<<st.top()<<' ';
        st.pop();
    }
    g<<'\n';
    return 0;
}
