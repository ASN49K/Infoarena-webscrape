#include <stdio.h>
#include <fstream>
int T, A, B;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    in >> T;
    for (; T; --T)
    {
        in >> A >> B;
        out << gcd(A, B);
    }
    return 0;
}