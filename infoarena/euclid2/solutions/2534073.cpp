#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t, a, b;
    fin >> t;
    while (t > 0) {
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
        --t;
    }
    return 0;
}
