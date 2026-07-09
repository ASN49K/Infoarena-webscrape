#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES freopen("cmlsc.in", "r", stdin); freopen("cmlsc.out", "w", stdout);

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const int NMAX = 1024;
int a[NMAX], b[NMAX], v[NMAX][NMAX];
int ans[NMAX], pos = 0;

signed main() {
    //#ifndef ONLINE_JUDGE
        FASTIO; FILES;
    //#endif // ONLINE_JUDGE

    int n, m, i, j;
    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(j = 1; j <= m; j++)
        cin >> b[j];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j],  v[i][j - 1]);

    i = n, j = m;
    while(i > 0 && j > 0) {
        //cout << i << ' ' << j << '\n';
        if(a[i] == b[j]) {
            ans[pos++] = a[i];
            i--;
            j--;
        } else if(v[i][j] == v[i - 1][j]) {
            i--;
        }
        else if(v[i][j] == v[i][j - 1]) {
            j--;
        }
    }

    cout << pos << '\n';

    for(int i = pos - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}
