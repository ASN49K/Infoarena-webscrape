#include <bits/stdc++.h>
using namespace std;
 
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long n, a, b, aux;
int f_cmmdc (int x, int y) {
    while (y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> a >> b;
        aux = f_cmmdc(a, b);
        fout << aux << endl;
    }
    return 0;
}