/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize ("O3,Ofast,unroll-loops")
#define pb push_back
#define f first
#define s second
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.f == p2.f) return p1.s > p2.s;
    return p1.f < p2.f;
}

signed main(){
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");
    
    int m, n;cin >> m >> n;
    
    vector<int> a(m + 1), b(n + 1);
    for(int i=1;i <= m;i++)cin >> a[i];
    for(int j=1;j <= n;j++)cin >> b[j];
    
    vector<pair<int, int>> v;
    for(int i=1;i <= m;i++)
        for(int j=1;j <= n;j++)
            if(a[i] == b[j])v.pb({i, j});
    
    sort(v.begin(), v.end(), cmp);
    vector<int> dp, parent(v.size(), -1), pos;
    
    for(int i=0;i < v.size();i++){
        int val=v[i].s;
        int k=lower_bound(dp.begin(), dp.end(), val) - dp.begin();
        
        if(k == dp.size()){
            dp.pb(val);
            if(k > 0)parent[i]=pos[k - 1];
            pos.pb(i);
        }else{
            dp[k]=val;
            if(k > 0)parent[i]=pos[k - 1];
            pos[k]=i;
        }
    }
    
    vector<int> ans;
    if(!pos.empty()){
        int x=pos.back();
        while(x != -1){
            ans.pb(a[v[x].f]);
            x=parent[x];
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(auto x : ans)cout << x << " ";
    cout << '\n';
    return 0;
}
