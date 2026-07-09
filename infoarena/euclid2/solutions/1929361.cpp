#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int n, x, y;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> x >> y;
        out << gcd(x, y) << "\n";
    }

    return 0;
}
