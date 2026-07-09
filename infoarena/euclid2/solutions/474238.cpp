#include <fstream>

using namespace std;

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);

    f >> T;

    for (; T; --T)
    {
        f >> A >> B;

        g << gcd(A, B) << endl;
    }

    return 0;
}

