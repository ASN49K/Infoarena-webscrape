#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

int euclid(int a, int b){
    if(b == 0)
        return a;
    else
        return euclid(b, a % b);
}

void solve(){
    int a, b;
    cin >> a >> b;
    cout << euclid(a, b) << '\n';
}
 
int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}