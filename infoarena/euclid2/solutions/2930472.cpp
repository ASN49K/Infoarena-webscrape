#include <bits/stdc++.h>
using namespace std;

int euclid(int a, int b) {
    if (!b)
        return a;
    return euclid(b, a % b);
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n;
    fin >> n;

    for (int i = 1, a, b; i <= n; ++i) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
}