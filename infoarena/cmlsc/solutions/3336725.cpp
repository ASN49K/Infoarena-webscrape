#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("cmisc.in");
    ofstream cout("cmisc.out");
    int m,n;
    cin>>m>>n;
    vector<int> a(m);
    vector<int> b(n);
    
    for(int i=0; i<m; ++i)
        cin>>a[i];

    for(int j=0; j<n; ++j)
        cin>>b[j];

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=m-1; i>=0; --i)
        for(int j=n-1; j>=0; --j){
            if(a[i]==b[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }

    cout<<dp[0][0]<<"\n";
    vector<int> ans;
    int i=0, j=0;
    while(i<m && j<n){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            ++i; ++j;
        }else if(dp[i+1][j] >= dp[i][j+1]){
            ++i;
        }else{
            ++j;
        }
    }
    for(size_t k=0; k<ans.size(); ++k){
        if(k) cout<<" ";
        cout<<ans[k];
    }
    if(!ans.empty()) cout<<"\n";
    
}
