#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long Cmmdc(long long a, long long b);
int main()
{
    long long a, b, n;
    fin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        fin >> a >> b;
        fout << Cmmdc(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}

long long Cmmdc(long long a, long long b)
{
    long long rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    }while ( rest );
    return a;
}
