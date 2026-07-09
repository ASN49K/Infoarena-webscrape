#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <cmath>
#include <string>
#include <deque>
#include <array>
#include <tuple>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
///#include <windows.h>

#pragma GCC optimize("fast-math")

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define psi pair<short int, short int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin() + 1, (x).end()
#define all0(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend() - 1
#define allrev0(x) (x).rbegin(), (x).rend()
#define println(thing) cout << thing << '\n'
#define yes println("YES")
#define no println("NO")
#define maybe println("MAYBE")
#define mda println("/////////////////")
#define msb(x) ((x) == 0 ? 0 : (1 << (64 - __builtin_clzll(x) - 1)))
#define lsb(x) ((x) & (-x))

using namespace std;

mt19937_64 rng(chrono :: steady_clock :: now().time_since_epoch().count());

const size_t fixed_random = rng();

clock_t start_time = clock(), end_time;

ll random_seed(ll modulo) {
    return rng() % modulo;
}

template <typename T>
inline void hash_combine(size_t& seed, const T& value) {
    seed ^= hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator () (const pair<T1, T2>& p) const {
        size_t seed = fixed_random;

        hash_combine(seed, p.fir);
        hash_combine(seed, p.sec);

        return seed;
    }
};

struct normal_hash {
    template <typename T>
    size_t operator () (const T& p) const {
        size_t seed = fixed_random;

        hash_combine(seed, p);

        return seed;
    };
};

template <typename unordered_Map>
void optimize_map(unordered_Map& M) {
    M.reserve(1024);
    M.max_load_factor(0.5);
}

template <typename T1, typename T2>
istream& operator >> (istream& in, pair<T1, T2>& p) {
    in >> p.first >> p.second;
    return in;
}

template <typename T1, typename T2>
ostream& operator << (ostream& out, pair<T1, T2>& p) {
    out << p.first << ' ' << p.second;
    return out;
}

/// for bitset bits
template <typename T1, typename T2> T1 operator ^= (T1 t1, T2 t2) {t1 = t1 ^ t2; return t1;}
template <typename T1, typename T2> T1 operator |= (T1 t1, T2 t2) {t1 = t1 | t2; return t1;}
template <typename T1, typename T2> T1 operator &= (T1 t1, T2 t2) {t1 = t1 & t2; return t1;}

const ll NMX = (ll) 1e7;
const ll MOD = (ll) 1e9 + 7;
const ll INF = (ll) 1e18;

ll binExp(ll base, ll exp) {
    ll P = 1;
    for (ll bit = 1; bit <= exp; bit <<= 1) {
        if (exp & bit)
            P = (P * base) % MOD;
        base = (base * base) % MOD;
    }
    return P;
}

inline ll modInv(ll x) {
    return binExp(x, MOD - 2);
}

ll test_case = 0;

void solve(ll testcase)
{
    ll a, b;
    cin >> a >> b;
    return cout << __gcd(a, b) << '\n', void();
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    ///cout << fixed << setprecision(20);

    ll tt; cin >> tt; while (tt--)
       solve(++test_case);
    \

    return 0;
}

/**

///

**/
