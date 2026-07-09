#include <fstream>

using namespace std;

int gcd(int a, int b) {

    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {

    int a, b, T;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> T;
    while(T--) {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }

    in.close();
    out.close();

    return 0;
}
