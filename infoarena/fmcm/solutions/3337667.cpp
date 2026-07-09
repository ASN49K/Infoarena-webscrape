/// C++, stii ca trag pe nas
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;

const int mod = 1000000007, maxN = 200000;
int n, c, p[maxN + 5], frecv[maxN + 5];
bool marked[maxN + 5], marked2[maxN + 5];
string str;

int lgput(int x, int p) {
    if (p == 0) {
        return 1;
    }

    if (p % 2 == 0) {
        int k = lgput(x, p/2);
        return 1LL * k * k % mod;
    } else {
        int k = lgput(x, p - 1);
        return 1LL * k * x % mod;
    }
}

vector <pair <int, int>> decompose(int x) {
    vector <pair <int, int>> factors;
    for (int d = 2; d * d <= x; d++) {
        if (x % d) {
            continue;
        }
        int f = 0;
        while (x % d == 0) {
            f++;
            x /= d;
        }
        factors.emplace_back(d, f);
    }
    if (x > 1) {
        factors.emplace_back(x, 1);
    }
    return factors;
}

void add(int x) {
    while (x != 1) {
        int curr = p[x];
        frecv[curr]++;
        x /= curr;
    }
}

void checkBrute() {
    vector <int> toChange;
    ll ans = 2;
    for (int i = 2; i < n; i++) {
        if (str[i - 1] == '?') {
            ans = 2LL * ans;
            if ((i - 1) % 2 != 0) {
                toChange.push_back(i - 1);
            }
            continue;
        }
        if (str[i - 1] == '1') {
            ans = 2LL * ans;
        } else {
            ans = 1LL * ans * (i - 1);
        }
    }
    if (ans % c == 0) {
        bool changed = 0;
        for (int x : toChange) {
            ans /= 2;
            ans *= x;
            if (ans % c != 0) {
                changed = 1;
                break;
            }
        }
        if (changed) {
            ans %= mod;
        } else {
            ans = -1;
        }
    } else {
        ans %= mod;
    }
    cout << ans << '\n';
}

void solve() {
    cin >> n >> c;
    cin >> str;
    if (str[0] == '0' || str.back() == '0') {
        cout << "-1\n";
        return;
    }
    if (str[1] == '?') {
        str[1] = '0';
    }
//    if (n <= 22) {
//        checkBrute();
//        return;
//    }
    vector <pair <int, int>> factors = decompose(c);

    vector <int> toChange;
    int ans = 2;
    frecv[2] = 1;
    for (int i = 2; i < n; i++) {
        if (str[i - 1] == '?') {
            ans = 2LL * ans % mod;
            frecv[2]++;
            if ((i - 1) % 2 != 0) {
                toChange.push_back(i - 1);
            }
            continue;
        }

        if (str[i - 1] == '1') {
            frecv[2]++;
            ans = 2LL * ans % mod;
        } else {
            add(i - 1);
            ans = 1LL * ans * (i - 1) % mod;
        }
    }
//    int inv2 = lgput(2, mod - 2);
    int inv2 = 1;
    bool sure = 0;
    if (factors.back().first < n) {
        int cnt = 0, num2 = 0;
        for (auto [f, x] : factors) {
            if (frecv[f] < x) {
                cnt++;
            }
            if (f == 2) {
                num2 = x;
            }
            marked2[f] = 1;
        }
        if (cnt == 0 && num2 > 0) {
            int cand = ans;
            int need = frecv[2] - num2 - 1;
            for (int x : toChange) {
                if (need == 0) {
                    break;
                }
                bool ok = 1;
                int y = x;
                while (x > 1) {
                    int curr = p[x];
                    if (marked2[curr]) {
                        ok = 0;
                    }
                    x /= curr;
                }
                if (ok) {
                    cand = 1LL * cand * inv2 % mod;
                    cand = 1LL * y;
                    need--;
                }
            }
            if (need == 0) {
                ans = cand;
            } else {
                ans = -1;
            }
        }

        for (auto [f, x] : factors) {
            marked2[f] = 0;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        frecv[i] = 0;
    }
}

void prec() {
    for (int i = 2; i <= maxN; i++) {
        if (marked[i]) {
            continue;
        }
        for (int j = i; j <= maxN; j += i) {
            p[j] = i;
            marked[j] = 1;
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nrt = 1;
    prec();
    cin >> nrt;
    while (nrt--) {
        solve();
    }
    return 0;
}
