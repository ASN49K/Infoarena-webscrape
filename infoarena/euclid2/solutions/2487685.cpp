#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main()
{
    int T;
    f>>T;
    while(T--)
    {
        int a, b;
        f>>a>>b;
        g<<GCD(a, b)<<'\n';
    }
    return 0;
}
