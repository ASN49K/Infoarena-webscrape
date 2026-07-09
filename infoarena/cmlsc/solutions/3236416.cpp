#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define all(a) (a).begin(),(a).end()
using namespace std;
const int maxn=1e5+5;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    int size = 0;
    for (auto v: mp) {
        if (v.S > 1) {
            size++;
        }
    }
    cout << size << endl;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 2) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}