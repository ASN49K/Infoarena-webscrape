#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
    if (!b)
        return a;
    return (b, a % b);
}

int main() {
    fin >> t;
    while (t--) {
        fin >> a >> b;
        fout << gcd(a, b);
    }
}
