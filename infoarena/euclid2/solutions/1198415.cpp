#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b ==0) {
        return a;
    } else {
        return gcd(b, a % b );
    }
}

int main() {
    ifstream in("./euclid2.in");
    ofstream out("./eucllid2.out");
    int t, a, b;
    in >> t;
    while (t-- > 0) {
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }
    return 0; 
}
