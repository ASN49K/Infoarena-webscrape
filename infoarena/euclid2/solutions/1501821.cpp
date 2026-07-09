#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,n,i=0;
    fin>>n;
    for(i=1;i<=n;i++)
    {
    fin>>a>>b;
    fout<<__gcd(a,b)<<"\n";
    }
}
