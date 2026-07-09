#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

long int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    in >> n;
    for(int i = 0, a, b; i < n; i++)
    {
        in >> a >> b;
        out << gcd(a,b) << '\n';
    }
    return 0;
}
