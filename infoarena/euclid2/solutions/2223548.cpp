#include <fstream>
#include <string>

using namespace std;

const string IN_FILE = "euclid2.in";
const string OUT_FILE = "euclid2.out";

int gcd(const int a, const int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ifstream in(IN_FILE);
    ofstream out(OUT_FILE);
    int T;
    in >> T;
    for (; T > 0; T--) {
        int a, b;
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }
    in.close();
    out.close();
    return 0;
}

