#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1025],y[1025];
int dp[1025][1025];
pair<int,int>ue[1025][1025];
stack<pair<int,int>>st;
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<=m;i++)
        fin>>y[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ue[i][j]={i,j};
                }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    ue[i][j]=ue[i][j-1];
                    dp[i][j]=dp[i][j-1];
                }
                else
                {
                    ue[i][j]=ue[i-1][j];
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    fout<<dp[n][m]<<"\n";
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cout<<ue[i][j].first<<" "<<ue[i][j].second<<"||";
            }
            //cout<<"\n";
        }
    pair<int,int>p=ue[n][m];
    while(p.first>0&&p.second>0)
    {
        st.push(p);
        //cout<<p.first<<" "<<p.second<<"\n";
        p=ue[p.first-1][p.second-1];
    }
    while(!st.empty())
    {
        fout<<x[st.top().first]<<" ";
        st.pop();
    }
}
