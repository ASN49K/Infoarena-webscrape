#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int Gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base :: sync_with_stdio (false);
    int t, a, b;
    fin >> t;
    while (t--) {
        fin >> a >> b;
        fout << Gcd(a, b) << "\n";
    }
    return 0;
}
