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
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");


    f>>T;
    for (; T; --T)
    {
        f>>A>>b;
        g<< gcd(A, B)<<'\n';
    }

    return 0;
}
