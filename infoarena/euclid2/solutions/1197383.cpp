#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b);

int main()
{
    int t, a, b;
    in >> t;
    for(;t;--t)
    {
        in >> a >> b;
        out << gcd(a, b);
    }
    return 0;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
