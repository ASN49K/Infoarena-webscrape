#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int Q;
void solve() {
    int N, s = 0;
    fin >> N;
    for(int i = 1, x; i <= N; i++) {
        fin >> x;
        s ^= x;
    }
    if(s > 0) {
        fout << "DA\n";
    } else {
        fout << "NU\n";
    }
}
int main() {
    for(fin >> Q; Q--; solve());
    return 0;
}
