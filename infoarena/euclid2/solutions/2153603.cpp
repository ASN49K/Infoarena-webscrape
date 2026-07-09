#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, x, y, i;
int gcd(int x, int y)
{
    if (x==y) return x;
    if (x==0) return y;
    if (y==0) return x;
    if (!(x&1))
    {
        if (!(y&1)) return gcd(x>>1, y>>1)<<1;
        else return gcd(x>>1, y);
    }
    if (!(y&1))
        return gcd(x, y>>1);
    if (x>y) return gcd((x-y)<<1, y);
    else return gcd((y-x)<<1, x);
}
int main()
{
    fin >> n;
    for (i=1; i<=n; i++)
    {
        fin >> x >> y;
        fout << gcd(x, y) << "\n";
    }
    return 0;
}
