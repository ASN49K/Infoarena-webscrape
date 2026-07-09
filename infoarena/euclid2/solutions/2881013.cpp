#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define dbg(x) cout << #x <<": " << x << "\n";
#define sz(x) ((int)x.size())

using ll = long long;

const string fn = "euclid2";
ifstream fin(fn + ".in");
ofstream fout(fn + ".out");

int t;

int gcd(int a, int b){
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){

    fin >> t;
    while(t--){
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    return 0;
}