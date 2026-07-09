#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T;
    in >> T;
    int a, b;
    while (T--) {
        in >> a >> b;

        out << gcd(a, b) << endl;
    }

    in.close();
    out.close();

    return 0;
}