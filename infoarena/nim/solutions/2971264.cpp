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
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        x ^= a;
    }
    cout << (x == 0 ? "NU\n" : "DA\n");
}  
 
int main(){
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}