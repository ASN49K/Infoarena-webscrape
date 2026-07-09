#include <fstream>
#include <vector>
using namespace std;
int n,m;
const int maxn=1025;
int v1[maxn],v2[maxn];
struct sigma{
    int lungime;
};
int drum[maxn*100];
sigma dp[maxn][maxn];
int cnt[maxn][maxn];
void lcs(int i,int j){
    if(cnt[i][j]==1)return;
    if(i==0 || j==0)return;
    cnt[i][j]=1;
    if(v1[i]==v2[j]){
        lcs(i-1,j-1);
        if(dp[i][j].lungime<dp[i-1][j-1].lungime+1){
            dp[i][j].lungime=dp[i-1][j-1].lungime+1;
        }
        return;
    }else{
        lcs(i,j-1);
        lcs(i-1,j);
        if(dp[i][j].lungime<dp[i][j-1].lungime){
            dp[i][j].lungime=dp[i][j-1].lungime;
        }
        if(dp[i][j].lungime<dp[i-1][j].lungime){
            dp[i][j].lungime=dp[i-1][j].lungime;
        }
        return;
    }
}
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for (int i = 1; i <=n; i++) {
        cin>>v1[i];
    }
    for (int i = 1; i <=m; i++) {
        cin>>v2[i];
    }
    lcs(n,m);
    cout<<dp[n][m].lungime<<'\n';
    int i=n,j=m;
    int timer=dp[n][m].lungime-1;
    while(i>0 && j>0){
        if(v1[i]==v2[j]){
            drum[timer--]=v1[i];
            i--;
            j--;
        }
        else if(dp[i][j-1].lungime<dp[i-1][j].lungime){
            i--;
        }else{
            j--;
        }
    }
    for(int i=0;i<dp[n][m].lungime;i++)cout<<drum[i]<<" ";
    return 0;
}