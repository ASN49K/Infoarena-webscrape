#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1025;
int a[NMAX],b[NMAX],rasp[NMAX];
int dp[NMAX][NMAX];
pair<int,int> prevv[NMAX][NMAX];

int main()
{
    int n,m;
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> a[i];
    for(int i=1;i<=m;i++) fin >> b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                prevv[i][j]=make_pair(i-1,j-1);
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j]<dp[i][j-1])
                      prevv[i][j]=make_pair(i,j-1);
                else  prevv[i][j]=make_pair(i-1,j);
            }
        }
    }
    fout << dp[n][m] << '\n';
    bool ok=false;
    int x=n,y=m,k=0;
    while(ok==false){
        if(prevv[x][y].first==x-1 and prevv[x][y].second==y-1){
            rasp[++k]=a[x];
        }
        x=prevv[x][y].first;
        y=prevv[x][y].second;
        if(x==0 and y==0) ok=true;
    }
    for(int i=k;i>=1;i--) fout << rasp[i] << ' ';
    return 0;
}
