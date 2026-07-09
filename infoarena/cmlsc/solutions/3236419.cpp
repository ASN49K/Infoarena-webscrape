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
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n, m;
    in >> n >> m;
    // vector<int> a(n), b(m);
    int *a = new int[n];
    int *b = new int[m];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        in >> b[i];
        mp[b[i]]++;
    }
    int size = 0;
    for (auto v: mp) {
        if (v.S > 1) {
            size++;
        }
    }
    out << size << endl;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 2) {
            out << a[i] << " ";
        }
    }
    out << endl;
    return 0;
}