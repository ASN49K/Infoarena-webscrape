#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES freopen("podm.in", "r", stdin); freopen("podm.out", "w", stdout);

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

signed main() {
    //#ifndef ONLINE_JUDGE
        FASTIO; FILES;
    //#endif // ONLINE_JUDGE

    int n, m;
    cin >> n >> m;
    vector < vector <int> > v(n + 1, vector <int> (m + 1));

    vector < int > a(n + 1);
    vector < int > b(m + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            v[i][j] = max({(a[i] == b[j]) + v[i - 1][j - 1], v[i - 1][j],  v[i][j - 1]});
        }
    vector <int> ans;
    int i = n, j = m;
    while(i - 1 && j - 1) {
        if(v[i][j] == v[i - 1][j - 1] + (a[i] == b[j])) {
            ans.push_back(a[i]);
            i--;
            j--;
        } else if(v[i][j] == v[i - 1][j]) {
            i--;
        }
        else if(v[i][j] == v[i][j--]) {
            j--;
        }
    }

    cout << ans.size() << '\n';

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
