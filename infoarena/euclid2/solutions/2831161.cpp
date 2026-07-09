#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

const string fn = "file";


ifstream fin(fn + ".in");
ofstream fout(fn + ".out");

int n;

int gcd(int a, int b) {

    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int a, b;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}


