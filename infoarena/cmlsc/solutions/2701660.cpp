#include <bits/stdc++.h>
using namespace std;

struct marijuana {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; unordered_map <int, deque <int>, marijuana> Hash;

int lis(vector <int> &v) {
    vector <int> deck;
    for (auto &x: v) {
        auto it = upper_bound(deck.begin(), deck.end(), x - 1);
        if (it == deck.end())
            deck.push_back(x);
        else
            *it = x;
    }

    return deck.size();
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (auto &it: a)
        cin >> it;

    vector <int> b(m);
    for (auto &it: b)
        cin >> it;

    for (int i = 0; i < n; i++)
        Hash[a[i]].push_front(i);

    vector <int> c;
    for (auto &it: b)
        for (auto &x: Hash[it])
            c.push_back(x);

    cout << lis(c);
    return 0;
}