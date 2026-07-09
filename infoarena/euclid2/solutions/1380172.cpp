#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b > 0) return gcd(b, a % b);
    else return a;
}

int main()
{
    int a, b;
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    f >> a >> b;
    int ans = gcd(a, b);
    ans = min(ans, 30000);
    if (ans == 1) ans = 0;
    g << ans;
    f.close();
    g.close();
    return 0;
}
