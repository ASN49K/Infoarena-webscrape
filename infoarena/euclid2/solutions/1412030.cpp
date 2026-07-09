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

#define MAXN 100

int euclid(int a, int b) {
    while(b)
        return euclid(b, a % b);
    return a;
}

void read() {
    #ifndef ONLINE_JUDGE
    assert(freopen("euclid2.in", "r", stdin));
    assert(freopen("euclid2.out", "w", stdout));
    #endif

    int n;
	scanf("%d", &n);
	while(n--) {
	    int x, y;
	    scanf("%d%d", &x, &y);
        printf("%d\n", euclid(x, y));
	}
}

int main() {
	read();

    return 0;
}
