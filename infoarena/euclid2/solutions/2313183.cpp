#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b;
int euclid(int a, int b) {
    int c;
    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main() {
    int T;
    fin >> T;
    for (int i = 0; i < T; i++) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}