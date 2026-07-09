#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;
const int mod1=998244353;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,a,b;

int gcd(int a,int b){
    if(a==1) return 1;
    else if(a==0 || b==0) return max(a,b);
    return gcd(b,a%b);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> a >> b;
        cout << gcd(a,b) << '\n';
    }
}
