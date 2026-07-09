#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,c,i,j,r;
int main()
{
    fin>>a;
    for (i=1;i<=a;i++)
    {fin>>b>>c;fout<<__gcd(b,c)<<'\n';}
    return 0;
}
