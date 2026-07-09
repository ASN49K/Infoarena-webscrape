#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

ll mod = 998244353;
vector<bool> is_prime(3*1e5+1, true);

void sieve(int n = 3*1e5){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    sieve();
    ll primes_prod = 1, current = 1, tot = 0;
    for(int i = 1; i <= n; i++){
        tot += binpow(m, i, mod);
        tot %= mod;
    }
    for(int i = 1; i <= n; i++){
        if(is_prime[i])
            primes_prod *= i;
        if(primes_prod > m)
            break;
        current *= (m / primes_prod) % mod;
        current %= mod;
        tot -= current;
        tot = ((tot % mod) + mod) % mod;
    }
    cout << tot << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}