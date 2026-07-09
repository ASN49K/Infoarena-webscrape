#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int lcs_table[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                lcs_table[i][j] = 0;
            else if(a[i-1] == b[j-1])
                lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
            else 
                lcs_table[i][j] = (lcs_table[i-1][j] > lcs_table[i][j-1] ? lcs_table[i-1][j] : lcs_table[i][j-1]);
        }
    }
    int index = lcs_table[n][m];
    int lcs[index];
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs[index-1] = a[i-1];
            i--;
            j--;
            index--;
        } else if(lcs_table[i-1][j] > lcs_table[i][j-1])
            i--;
        else
            j--;
    }
    cout << sizeof(lcs) / sizeof(lcs[0]) << '\n';
    for(auto i : lcs)
        cout << i << ' ';
    cout << '\n';
}
 
int main(){
    freopen("cmslc.in", "r", stdin);
    freopen("cmslc.out", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}