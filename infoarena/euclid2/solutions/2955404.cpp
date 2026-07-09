#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int main()
{
    f >> t;

    while (t--) {
        f >> a >> b;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        g << a << "\n";
    }

    return 0;
}
