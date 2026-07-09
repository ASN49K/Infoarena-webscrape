#include <fstream>

using namespace std;

int main()
{
    int t, a, b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> t;
    while (t--) {
        f >> a >> b;
        int gcd = 1, q = min(a, b);
        for (int i = q; i >= 2; i--)
            if (a % i == 0 && b % i == 0) {
                gcd = i;
                break;
            }
        g << gcd << "\n";
    }
    f.close();
    g.close();
    return 0;
}
