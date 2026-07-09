#include <bits/stdc++.h>
#include <list>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i , n) for(int i = 0 ; i < (n) ; i++)
#define N 201
#define apare printf("apare");
#define endl "\n"
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> pii;
const int inf = 1e6;

list<int> LCS(vector<int> s , vector<int> d , int n , int m){
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i - 1] == d[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

        }
    }
    int i = n;
    int j = m;
    list<int> ret;
    for( ; i ; ){
        if(s[i - 1] == d[j - 1]){
            ret.push_front(s[i - 1]);
            i-- , j--;
        }
        else
            if(dp[i - 1][j] < dp[i][j - 1])
                j--;
            else
                i--;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("cmlsc.in" , "r" , stdin);
    freopen("cmlsc.out" , "w" , stdout);

    int n , m ;
    cin >> n >> m;
    vector<int> sequence1(n , 0);
    vector<int> sequence2(m , 0);
    for(int i = 0 ; i < n ; i++)
        cin >> sequence1[i];
    for(int j = 0 ; j < m ; j++)
        cin >> sequence2[j];
    list<int> ret = LCS(sequence1 , sequence2 , n  , m);
    cout << ret.size() << endl;
    for(auto it : ret){
        cout << it << " ";
    }
    return 0;
}