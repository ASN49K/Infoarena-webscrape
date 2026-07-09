#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int x, int y){
    int r;
    while(y != 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

signed main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    int t, a, b;
    fin>>t;
    while(t--){
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
    return 0;
}

