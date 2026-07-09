#include <fstream>
#include <iostream>

using namespace std;
int gcd(int a, int b) {
    if (b > 0)
        return gcd(b, a % b);
    else
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
        int q = min(a, b), gcd = 1;
        for (int i = 2; i <= q; i++) {
            if (a % i == 0 && b % i == 0 && gcd % i != 0)
                gcd *= i;
        }
        g << gcd << "\n";
    }
    f.close();
    g.close();
    return 0;
}
