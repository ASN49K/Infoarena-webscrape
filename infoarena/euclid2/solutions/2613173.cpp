#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordset;
*/

#define fr first
#define sc second
#define vec vector
#define pb push_back
#define pii pair<int, int>
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;

typedef long long ll;
typedef unsigned int uint;
const int nmax = 300005;
const ll linf = LLONG_MAX;
const int mod = 1e9+7;
const int inf = INT_MAX;

ll t, a, b;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    cin >> t;
    while(t--){
        fin >> a >> b;
        fout << __gcd(a,b);
    }
}
