#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1026;
int a[NMAX],b[NMAX],dp[NMAX][NMAX];
pair <int,int> pre[NMAX][NMAX];
int n,m,rasp[NMAX];
void citire(){
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> a[i];
    for(int i=1;i<=m;i++) fin >> b[i];
}
void dinamica(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                pre[i][j]={i-1,j-1};
            } else {
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    pre[i][j]={i-1,j};
                } else {
                    dp[i][j]=dp[i][j-1];
                    pre[i][j]={i,j-1};
                }
            }
        }
    }
}
void solve(){
    int i=n,j=m,k=0;
    while(i!=0 and j!=0){
        if(a[i]==b[j]){
            rasp[++k]=a[i];
            i--,j--;
        } else {
            int aux=i;
            i=pre[i][j].first;
            j=pre[aux][j].second;
        }
    }
}
void afis(){
    fout << dp[n][m] << '\n';
    for(int i=dp[n][m];i>=1;i--)
        fout << rasp[i] << ' ';
}
int main()
{
    citire();
    dinamica();
    solve();
    afis();
    return 0;
}
