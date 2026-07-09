#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int64;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
string __fname = "nim"; ifstream in (__fname + ".in"); ofstream out (__fname + ".out"); 
#define cin in 
#define cout out
#define uint64 unsigned long long
#define x first
#define y second
#define sz(x)(int) x.size()
#define pb push_back
#define pii pair <int, int> 
#define pii64 pair <int64, int64>
#define ss cout << " "
#define nn cout << "\n"
#define ct(x) cout << (x)
#define cts(x) cout << (x) << " "
#define ctn(x) cout << (x) << "\n"
#define db(x) cout << "> " << #x << ": " << (x) << "\n"
#define qr queries()
#define yn(x) if (x) {ctn("Yes");}else {ctn("No");}
void solve(int);
void queries(){int n;cin >> n;for (int i = 1; i <= n; i++) solve(i);}
int64 ceildiv(int64 a, int64 b) {return a / b + !!(a % b);}
template<class T>T gcd (T a, T b){return (b ? gcd(b, a % b): a);}
template<class T>T lcm (T a, T b){return a * b / gcd(a, b);}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
const int maxn = 200200;
const double pi = 3.14159265359;
const int64 mod = 1000000007;
const int64 hash_p = 101;
const int64 hash_inv = 940594066;
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void solve(int id){
    int n;
    cin >> n;
    int xr = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        xr^=x;
    }
    if (xr) {
        ctn("DA");
    }
    else {
        ctn("NU");
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); ct(fixed); ct(setprecision(10)); 
    qr;
    return 0;
}