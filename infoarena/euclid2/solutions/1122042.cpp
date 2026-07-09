#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid.out");

long long int gcd(long long int a, long long int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    in >> n;
    for(long long int i = 0, a, b; i < n; i++)
    {
        in >> a >> b;
        oout << gcd(a,b) << '\n';
    }
    return 0;
}
