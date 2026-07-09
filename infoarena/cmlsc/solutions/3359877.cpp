/*  
    *
    * soon on twitch : ex3qute 
    * 
    * ax ah al
    * kwxkwxkxkxwkxkwxkw
    * dumnezeu sa o ierte
*/


#include <bits/stdc++.h>  
using namespace std;  
#define ull unsigned long long  
#define ll long long  
#define pb push_back  
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);  
const int MOD = 1e9+7;
int di[4]={0,0,-1,1};  
int dj[4]={-1,1,0,0};  

#ifndef exe
#define cin f
#define cout g
#endif

int get(vector<int>& a, vector<int>& b, int i, int j) {
    if(i == 0 || j == 0) return 0;
    else if(a[i] == b[j]) return 1 + get(a,b,i-1,j-1);
    else {
        int x = get(a,b,i-1,j);
        int y = get(a,b,i,j-1);
        return max(x,y);
    }
}

vector<int> idxs;
void bkt(vector<int>& a, vector<int>& b, int i, int j) {
    if(i == 0 || j == 0) return;
    else if(a[i] == b[j]){
        idxs.pb(i);
        bkt(a,b,i-1,j-1);
    }

    else {
        int x = get(a,b,i-1,j);
        int y = get(a,b,i,j-1);

        if(x > y) bkt(a,b,i-1,j);
        else bkt(a,b,i,j-1);
    }

}

signed main(){   
    

    int n,m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=m;++i) cin >> b[i];

    cout << get(a,b,n,m) << '\n';
    bkt(a,b,n,m);

    sort(idxs.begin(), idxs.end());
    for(auto idx : idxs) cout << a[idx] << ' ';


    return 0;
}


