#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t;
    in >> t;

    while(t--)
    {
        int a, b;
        in >> a >> b;

        out << __gcd(a,b) << '\n';
    }

    return 0;
}
