#include <iostream>
#include <fstream>
using namespace std;

int v[100001];

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T, a, b, poz = 0;
    fin >> T;
    for (int i = 1; i <= T; ++i) {
        fin >> a >> b;
        v[++poz] = a;
        v[++poz] = b;
    }
    for (int i = 1; i <= poz; i += 2) {
        while (v[i + 1] != 0) {
            int rest = v[i] % v[i + 1];
            v[i] = v[i + 1];
            v[i + 1] = rest;
        }
        fout << v[i] << "\n";
    }
}
