#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;
int a[1025],b[1025];
int dp[1025][1025];
pair <int,int> last[1025][1025];
stack <int> st;

int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
        fin>>a[i];
    for(int i=1; i<=n; i++)
        fin>>b[i];
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                last[i][j]=make_pair(i-1,j-1);
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    last[i][j]=make_pair(i-1,j);
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    last[i][j]=make_pair(i,j-1);
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    pair <int,int> x=make_pair(m,n);
    while(x.first>0 && x.second>0)
    {
        if(a[x.first]==b[x.second])
            st.push(a[x.first]);
        x=last[x.first][x.second];
    }
    fout<<dp[m][n]<<"\n";
    while(!st.empty())
    {
        fout<<st.top()<<" ";
        st.pop();
    }
    fout<<"\n";
    return 0;
}
