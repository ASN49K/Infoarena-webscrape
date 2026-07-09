#include <fstream>

using namespace std;
int gcd(int a, int b) {
    if (a > b)
        return gcd(a - b, b);
    else if (a < b)
        return gcd(a, b - a);
    else if (a == b)
        return a;
}

int main()
{
    int t, a, b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    while (t--) {
        f >> a >> b;
        g << gcd(a, b) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
