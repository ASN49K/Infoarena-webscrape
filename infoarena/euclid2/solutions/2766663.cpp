#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int n, i, a, b, r;
    fin >> n;
    for(i = 1; i <= n; ++i) {
        fin >> a >> b;
        while(a != 0) {
            r = b % a;
            b = a;
            a = r;
        }
        fout << b << '\n';
    }
    return 0;
}
