#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


int dp[1030][1030];
int v[1030],w[1030];
int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)cin>>v[i];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(w[i]==v[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[m][n]<<"\n";
    vector<int>dr;
    int i=m,j=n;
    while(i>0||j>0){
        if(w[i]==v[j] && dp[i][j]==dp[i-1][j-1]+1){
            dr.push_back(w[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])i--;
        else j--;
    }
    for(int i=dr.size()-1;i>=0;i--)cout<<dr[i]<<" ";
    return 0;
}
