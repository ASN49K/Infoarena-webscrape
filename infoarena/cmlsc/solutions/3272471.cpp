#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
const int maxn=1024;
int v1[maxn],v2[maxn];
struct sigma{
    int lungime; 
};
int maxnr=0;
vector<int> numeree;
sigma dp[maxn][maxn];
int cnt[maxn][maxn];
void lcs(int i,int j,vector<int> x){
    if(cnt[i][j]==1)return;
    if(i==0 || j==0)return;
    cnt[i][j]=1;
    if(v1[i]==v2[j]){
        x.push_back(v1[i]);
        lcs(i-1,j-1,x);
        if(dp[i][j].lungime<dp[i-1][j-1].lungime+1){
            dp[i][j].lungime=dp[i-1][j-1].lungime+1;
            if(maxnr<dp[i][j].lungime)
            {
                numeree=x;
                maxnr=dp[i][j].lungime;
            }
        }
        if(maxnr<x.size())
        {
            numeree=x;
            maxnr=x.size();
        }
        return;
    }else{
        lcs(i,j-1,x);
        lcs(i-1,j,x);
        if(dp[i][j].lungime<dp[i][j-1].lungime){
            dp[i][j].lungime=dp[i][j-1].lungime;
        }
        if(dp[i][j].lungime<dp[i-1][j].lungime){
            dp[i][j].lungime=dp[i-1][j].lungime;
        }
        if(maxnr<x.size())
        {
            numeree=x;
            maxnr=x.size();
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
    lcs(n,m,numeree);
    reverse(numeree.begin(),numeree.end());
    cout<<dp[n][m].lungime<<'\n';
    for(auto i:numeree)cout<<i<<" ";
    return 0;
}