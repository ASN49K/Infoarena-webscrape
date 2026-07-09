#include <iostream>
#include <fstream>

using namespace std;

static inline unsigned gcd(unsigned x, unsigned y)
{
    if(!y) return x;
    return gcd(y, x%y);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    in >> n;
    for(int i = 0; i < n; ++i)
    {
        unsigned x, y;
        in >> x >> y;
        out << gcd(x, y) << endl;
    }

    return 0;
}
