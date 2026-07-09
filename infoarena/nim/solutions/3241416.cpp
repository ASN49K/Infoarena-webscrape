#include<bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;

void solve(){
    int n, x, s = 0;
    fin >> n;
    for(;n--;){
        fin >> x;
        s ^= x;
    }
    fout << (s ? "DA\n" : "NU\n");
}

int main(){
    fin >> t;
    for(;t--;)
        solve();
}
