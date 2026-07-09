#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

typedef long long ll;

void Solve() {
    ll a, b, r;
    fin >> a >> b;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    fout << a << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fin >> t;
    while (t--)
        Solve();
    return 0;
}