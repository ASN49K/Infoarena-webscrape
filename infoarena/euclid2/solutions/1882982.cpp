#include <fstream>
using namespace std;

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t;

    fin >> t;
    while (t--) {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << endl;
    }
    return 0;
}