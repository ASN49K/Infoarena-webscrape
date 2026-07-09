#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long cmmdc( int a, int b)
{
    while(a != b)
    {
        if( a == 0) return b;
        else if (b == 0) return a;
        if( a > b)
        a = a%b;
    else b = b %a;
    }
    return a;
}
int main()
{
    long long t, a, b, i;
    fin >> t;
    for(i = 1; i <= t; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
