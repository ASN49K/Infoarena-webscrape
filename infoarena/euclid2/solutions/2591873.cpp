#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
ull cmmdc(ull a, ull b)
{
    while(b)
    {
        ull c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    fin >> t;
    for(int i = 1; i <= t; i++)
    {
        ull a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
