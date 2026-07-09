//
// Created by littlewho on 5/1/17.
//

#include <fstream>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int t;
    in >> t;

    int x, y;
    while (t--) {
        in >> x >> y;
        out << gcd(x, y) << "\n";
    }
}
