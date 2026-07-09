#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t;
    fin >> t;
    while (t--) {
        int a, b;
        fin >> a >> b;

        fout << __gcd(a, b) << '\n';
    }
    return 0;
}
