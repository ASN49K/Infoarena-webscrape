#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{

   fin>>n;
    for (; n; --n)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }

    return 0;
}
