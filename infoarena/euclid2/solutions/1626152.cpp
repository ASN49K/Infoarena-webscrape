#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
    if(a < b)
        swap(a, b);
    if(b == 0)
        return a;

    return euclid(b, a%b);
}

int main() {
    int T, n, m;

    fin >> T;
    while(T--) {
        fin >> n >> m;
        fout << euclid(n, m) << "\n";
    }
}
