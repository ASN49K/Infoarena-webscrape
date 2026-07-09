#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int solve() {
    int n, s = 0, a;
    f >> n;
    for (int i = 1; i <= n; ++i) {
        f >> a;
        s = s ^ a;
    }
    if (s) return 1;
    return 0;
}
int main()
{
    int t;
    f >> t;
    while (t--)
        if (solve()) g << "DA\n";
        else g << "NU\n";
    return 0;
}
