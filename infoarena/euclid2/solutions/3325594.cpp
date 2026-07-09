#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define setinf(x) memset(x,0x3f3f3f3f,sizeof(x));
#define set0(x) memset(x,0,sizeof(x));
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define DD 100001
#define nl '\n'
using namespace std;
const string file="euclid2";
ifstream f(file+".in");
ofstream g(file+".out");
//#define f cin
//#define g cout

int main(){
    int t;
    f>>t;
    while(t--) {
        int x,y;
        f>>x>>y;
        g<<__gcd(x,y)<<nl;
    }
    system("pause");
    return 0;
}
