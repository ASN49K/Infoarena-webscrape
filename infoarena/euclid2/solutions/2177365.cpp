#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream o("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
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
    int n;
    f >> n;

    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        f >> a >> b;
        o << cmmdc(a,b) << '\n';
    }

    return 0;
}
