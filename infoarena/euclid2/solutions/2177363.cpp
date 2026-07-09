#include <fstream>

using namespace std;

fstream f("euclid2.in");
ofstream o("euclid2.out");

long long cmmdc(long long a, long long b)
{
    long long r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    long long n;
    f >> n;

    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        f >> a >> b;
        o << cmmdc(a,b) << "\n";
    }

    return 0;
}
