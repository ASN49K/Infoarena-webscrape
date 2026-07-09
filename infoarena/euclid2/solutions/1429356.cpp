#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1025

using namespace std;

int euclid(int a, int b) {
    int r;

    r = a%b;
    while (r != 0) {
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    int n, i, a, b;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> n;

    for (i = 0; i<n; ++i) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }

    return 0;
}
