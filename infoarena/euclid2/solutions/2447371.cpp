#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int d, int i)
{
    int r;
    while(i)
    {
        r = d % i;
        d = i;
        i = r;
    }
    return d;
}
int k, a, b;
int main()
{
    fin >> k;
    while(k --)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}
