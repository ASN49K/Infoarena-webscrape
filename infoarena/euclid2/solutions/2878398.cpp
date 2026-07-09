#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

typedef long long ll;

vector<pair<ll, ll>> list;

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a + b;
    else if (a > b)
        return gcd(a % b, b);
    else
        return gcd(a, b % a);
}

void read_solve() {
    int t;
    fin >> t;
    
    for(int i = 1; i <= t; i++) {
        ll f, s;
        fin >> f >> s;
        list.push_back(make_pair(f, s));
    }
    
    for(int i = 0; i < t; i++)
        fout << gcd(list[i].first, list[i].second) << "\n";
        
}


int main() {
    read_solve();
    return 0;
}
