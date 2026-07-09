#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

const int dim=10009;

int n,v[dim];

void solve(){
    int XOR=0;
        fin>>n;
    for(int i=1;i<=n;i++){
        fin>>v[i];
        XOR=XOR^v[i];
    }
        fout<<(XOR ? "DA\n" : "NU\n");
}

signed main(){
    int t;
        fin>>t;
    while(t--){
        solve();
    }
}
