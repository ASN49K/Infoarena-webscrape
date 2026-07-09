#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned n,a,b,i;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
