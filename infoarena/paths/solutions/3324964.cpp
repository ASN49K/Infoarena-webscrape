#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
using ll = long long;

const int mod = 1'000'000'007;
const string filename = "paths";
const int maxN = 100005;
#define int ll

int n, k, v[maxN], add[maxN], ans[maxN];
pair <int, int> best[maxN], best2[maxN], bestUp[maxN];
set <pair <int, int>> bestK, others;
int bestSum;

//vector <int> G[maxN];
vector <pair <int, int>> G[maxN];

void dfs(int nod, int tata) {
    best[nod] = {0, nod};
    best2[nod] = {-1, nod};
    for (auto [fiu, cost] : G[nod]) {
        if (fiu == tata) {
            continue;
        }
        dfs(fiu, nod);
        auto p = best[fiu];
        p.first += cost;
        if (best[nod].second == nod || p > best[nod]) {
            best2[nod] = best[nod];
            best[nod] = p;
        } else if (best2[nod].second == nod || p > best2[nod]) {
            best2[nod] = p;
        }
    }
    for (auto [fiu, cost] : G[nod]) {
        if (fiu == tata) {
            continue;
        }
        if (best[fiu].second == best[nod].second) {
            continue;
        }
        add[best[fiu].second] = best[fiu].first + cost;
    }
}

void dfs2(int nod, int tata, int cost) {
    if (nod != 1) {
        bestUp[nod] = {bestUp[tata].first + cost, bestUp[tata].second};
        auto p = best[tata];
        if (p.second == best[nod].second) {
            p = best2[tata];
        }
        p.first += cost;
        if (p >= bestUp[nod]) {
            bestUp[nod] = p;
        }
    }
    for (auto [fiu, cost] : G[nod]) {
        if (fiu == tata) {
            continue;
        }
        dfs2(fiu, nod, cost);
    }
}

void printSets() {
    int sum = 0;
    for (auto p : bestK) {
        sum += p.first;
        cout << p.first << ' ' << p.second << '\n';
    }
    cout << '\n';
    for (auto p : others) {
        cout << p.first << ' ' << p.second << '\n';
    }
    cout << '\n';
    cout << "Sum is " << sum << '\n';
}

void update(int nod, int delta) {
    pair <int, int> p = {-add[nod], nod};
    auto it = bestK.find(p);
    if (it == bestK.end()) {
        others.erase(others.find(p));
    } else {
        bestSum -= p.first;
        bestK.erase(it);
    }
    p.first -= delta;
    add[nod] += delta;
    others.insert(p);
}

void fixSets(int nod) {
    for (int i = 0; i < 2; i++) {
        auto p1 = *bestK.rbegin();
        auto p2 = *others.begin();
        if (p2 < p1) {
            bestSum -= p1.first;
            bestK.erase(p1);
            others.erase(p2);
            bestSum += p2.first;
            bestK.insert(p2);
            others.insert(p1);
        }
    }
}

void dfs3(int nod, int tata) {
    for (auto [fiu, cost] : G[nod]) {
        if (fiu == tata) {
            continue;
        }
        update(best[fiu].second, -cost);
        update(bestUp[fiu].second, cost);
        while (bestK.size() < k) {
            bestSum += (*others.begin()).first;
            bestK.insert(*others.begin());
            others.erase(others.begin());
        }

        fixSets(nod);

        ans[fiu] = bestSum;
        dfs3(fiu, nod);

        update(best[fiu].second, cost);
        update(bestUp[fiu].second, -cost);
        while (bestK.size() < k) {
            bestSum += (*others.begin()).first;
            bestK.insert(*others.begin());
            others.erase(others.begin());
        }
        fixSets(nod);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }

    dfs(1, 0);

    add[best[1].second] = best[1].first;

    dfs2(1, 0, 0);

    others.insert({0, 0});
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) {
            cnt++;
            others.insert({-add[i], i});
        }
    }

    if (cnt < k) {
        k = cnt;
    }

    for (int i = 1; i <= k; i++) {
        ans[1] += (*others.begin()).first;
        bestSum += (*others.begin()).first;
        bestK.insert(*others.begin());
        others.erase(others.begin());
    }
    dfs3(1, 0);


    for (int i = 1; i <= n; i++) {
        cout << -ans[i] << '\n';
    }
}

signed main()
{
#ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    assert(freopen("test.out", "w", stdout));
#endif
#ifdef INFOARENA
	assert(freopen((filename + ".in").c_str(), "r", stdin));
    assert(freopen((filename + ".out").c_str(), "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nrt = 1;
//    cin >> nrt;
    while (nrt--) {
        solve();
    }
    return 0;
}
