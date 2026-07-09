//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordset;
*/

#define fr first
#define sc second
#define vec vector
#define pb push_back
#define pii pair<int, int>
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);

#define in fin
#define out fout

using namespace std;

typedef long long ll;
typedef unsigned int uint;
const int nmax = 300005;
const ll linf = LLONG_MAX;
const int mod = 1e9+7;
const int inf = INT_MAX;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, m;
int a[2000], b[2000];
pair <int,int > parent[2000][2000];
int dp[2000][2000];
int main(){
    in >> n >> m;
    for(int i = 1; i <= n; i++){
        in >> a[i];
    }
    for(int i = 1; i <= m; i++){
        in >> b[i];
    }
    pii mx = {0,0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            if(a[i]==b[j]){
                parent[i][j] = {i-1,j-1};
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            if(dp[i][j] <  dp[i][j-1]){
                parent[i][j] = {i,j-1};
                dp[i][j] = dp[i][j-1];
            }
            if(dp[i][j] <  dp[i-1][j]){
                parent[i][j] = {i-1,j};
                dp[i][j] = dp[i-1][j];
            }
            if(dp[mx.fr][mx.sc] < dp[i][j])mx.fr = i, mx.sc = j;
        }
    }
    out << dp[mx.fr][mx.sc] << '\n';
    stack <int> st;
    while(mx.fr && mx.sc ){
        if(a[mx.fr] == b[mx.sc]){
            st.push(a[mx.fr]);
        }
        pii next;
        next.fr = parent[mx.fr][mx.sc].fr;
        next.sc = parent[mx.fr][mx.sc].sc;
        mx = next;
    }
    while(!st.empty()){
        out << st.top() << ' ';st.pop();
    }
}
