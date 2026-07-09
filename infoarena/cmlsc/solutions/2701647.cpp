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
}; unordered_map <int, int, marijuana> Hash;

void lis(vector <int> &v, vector <int> &ref) {
    vector <int> deck;
    for (auto &x: v) {
        auto it = upper_bound(deck.begin(), deck.end(), x);
        if (it == deck.end())
            deck.push_back(x);
        else
            *it = x;
    }

    cout << deck.size() << endl;
    for (auto &it: deck)
        cout << ref[it] << ' ';
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

    int i;
    for (i = 0; i < n; i++) 
        Hash[a[i]] = i;

    vector <int> v;
    for (i = 0; i < m; i++) {
        int x;
        cin >> x;

        auto it = Hash.find(x);
        if (it != Hash.end())
            v.push_back(it->second);
    }

    lis(v, a);
    return 0;
}