#include <bits/stdc++.h>

using namespace std;

#define     mp              make_pair
#define     fs              first
#define     sc              second
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-7
#define     sz(a)           a.size()
#define     count_one       __builtin_popcount;
#define     count_onell     __builtin_popcountll;
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int T;
    int x, y;
    fin >> T;
    while(T--) {
    fin >> x >> y;
	fout << __gcd(x, y) << "\n";
    }
    return 0;
}
