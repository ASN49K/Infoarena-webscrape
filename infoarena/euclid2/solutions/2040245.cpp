#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b,i;
int main()
{
    fin>>T;
    for(i=1; i<=T; i++)
    {
        fin>>a>>b;
        fout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
