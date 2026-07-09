#include <fstream>
 
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
        g << gcd(a, b) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
