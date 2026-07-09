#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t;
    fin >> t;

    for (int i = 1; i <= t; ++i) {
        int a, b;
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
    }

    return 0;
}
