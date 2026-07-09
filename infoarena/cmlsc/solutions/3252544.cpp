#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
struct sir{
    int val,elem;
    pair<int,int> prev;
}dp[1025][1025];
int a[1025],b[1025],n,m,i,j,maxim,x,y;
void show(int x, int y){
    if(x && y){
        show(dp[x][y].prev.first, dp[x][y].prev.second);
        fout<<a[dp[x][y].elem]<<' ';
    }
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j].val = dp[i-1][j-1].val+1;
                dp[i][j].prev = {i-1,j-1};
                dp[i][j].elem = i;
            }else{
                dp[i][j] = dp[i-1][j-1];
            }
            if(dp[i][j].val < dp[i-1][j].val){
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j].val < dp[i][j-1].val){
                dp[i][j] = dp[i][j-1];
            }
            if(maxim < dp[i][j].val){
                x = i;
                y = j;
                maxim = dp[i][j].val;
            }
        }
    }
    fout<<maxim<<'\n';
    show(x,y);
    return 0;
}
