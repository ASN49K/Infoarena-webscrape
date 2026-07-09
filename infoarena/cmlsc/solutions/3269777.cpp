#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

vector<int>a,b,rasp;
vector<vector<int>>dp;
int main(){
    int n,m;
    cin>>n>>m;

    dp.resize(n+1,vector<int>(m+1));
    a.resize(n+1);
    b.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j-1]+(a[i]==b[j]),max(dp[i-1][j],dp[i][j-1]));
        }
    }

    int i=n,j=m;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j-1]+1 && (a[i]==b[j])){
            rasp.push_back(a[i]);
            i--;
            j--;
        }else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }

    cout<<dp[n][m]<<'\n';
    reverse(rasp.begin(),rasp.end());
    for(const auto&nr:rasp){
        cout<<nr<<" ";
    }
}