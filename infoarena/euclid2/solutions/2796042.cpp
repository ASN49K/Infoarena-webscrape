#include <iostream>
using namespace std;
#include <fstream>
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int sir[16];

void solve() {
    int a, b;
    fin >> a >> b;
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    fout << a << '\n';
}
int main() {
    fin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int T;
    fin >> T;
    while (T--)
        solve();
}
