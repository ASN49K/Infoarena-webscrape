#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int T, x, y;
    in >> T;
    while(T--)
    {
        out << __gcd(x,y) << '\n';
    }
    return 0;
}
