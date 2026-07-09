#include <fstream>
#include <algorithm>
using namespace std;
const int nmax = 10005;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    while(b)
    {
        unsigned long long r  = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n;
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        unsigned long long a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
