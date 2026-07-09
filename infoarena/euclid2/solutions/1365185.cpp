#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int gcd(int x, int y) {
    if(!y)
        return x;
    return gcd(y, x % y);
}

int main() {
    int t, x, y;
    fin >> t;
    while(t --) {
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }
}
