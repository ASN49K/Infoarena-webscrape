#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int euclid(int a, int b) {
    if (b == 0) return a;
    return euclid(b, a%b);
}

int main() {
    fin >> n;
    while (fin >> x >> y)
        fout << euclid(x, y) << "\n";
}
