#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N=1024;
int dp[N][N],a[N],b[N],num=0;

void sirul(int l, int c){
    if(l==0 || c==0){
        return;
    }
    if(a[l]==b[c]){
        sirul(l-1,c-1);
        cout<<a[l]<<" ";
    }else if(dp[l-1][c]>=dp[l][c-1]){
        sirul(l-1,c);
    }else{
        sirul(l,c-1);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=m; i++){
        cin>>b[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    sirul(n,m);
    return 0;
}
