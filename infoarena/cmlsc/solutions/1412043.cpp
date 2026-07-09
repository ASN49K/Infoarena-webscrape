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

#define MAXN 1025

int n, m;
int a[2][MAXN];
int din[MAXN][MAXN];

void read() {
    #ifndef ONLINE_JUDGE
    assert(freopen("cmlsc.in", "r", stdin));
    assert(freopen("cmlsc.out", "w", stdout));
    #endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	    scanf("%d", &a[0][i]);

    for(int i = 1; i <= m; ++i)
        scanf("%d", &a[1][i]);

//    for(int i = 1; i <= n; ++i)
//        din[0][i] = 1;//din[0][i] = a[0][i-1];
//    for(int i = 1; i <= m; ++i)
//        din[i][0] = 1;//    din[i][0] = a[1][i-1];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[0][i] == a[1][j])
                din[i][j] = din[i-1][j-1] + 1;
            else
                din[i][j] = max(din[i-1][j], din[i][j-1]);
        }
    }

    int res[MAXN];
    int len = 0;
    for(int i = n, j = m; i && j;) {
        if(din[i][j] == din[i-1][j-1] + 1)
            res[++len] = a[0][i],
            --i,
            --j;
        else if(din[i][j-1] > din[i-1][j])
            --j;
        else
            --i;
    }

    printf("%d\n", len);
    while(len) {
        printf("%d ", res[len--]);
    }

}

int main() {
	read();

    return 0;
}
