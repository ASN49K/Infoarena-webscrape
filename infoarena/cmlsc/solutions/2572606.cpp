#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1050;
int dp[NMAX][NMAX];
int n,m,a[NMAX],b[NMAX];
pair <int,int> prevv[NMAX][NMAX];

int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> a[i];
    for(int i=1;i<=m;i++) fin >> b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                prevv[i][j]=make_pair(i-1,j-1);
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j]<dp[i][j-1]){
                    prevv[i][j]=make_pair(i,j-1);
                }
                else{
                    prevv[i][j]=make_pair(i-1,j);
                }
            }
    fout << dp[n][m] << '\n';
    pair<int,int> x=make_pair(n,m);
    vector<int> rasp;
    while(x.first!=0 and x.second!=0){
        if(prevv[x.first][x.second]==make_pair(x.first-1,x.second-1))
            rasp.push_back(a[x.first]);
        x=prevv[x.first][x.second];
    }
    reverse(rasp.begin(),rasp.end());
    for(int i=0;i<rasp.size();i++)
    {
        fout << rasp[i] << ' ';
    }
    return 0;
}
