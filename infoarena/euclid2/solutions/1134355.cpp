#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("euclid2.in");
ifstream fout("euclid2.out");
unsigned n,a,b;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<__gcd(a,b);
    }
    return 0;
}
