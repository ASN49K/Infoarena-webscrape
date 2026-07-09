#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, tc, i, a, b;
int cmmdc (int a, int b)
{
    int rest = a%b;
    while (rest!=0)
    {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}
int main()
{
    fin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
