#include <fstream>
///https://infoarena.ro/problema/euclid2
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long cmmdc(long long a,long long b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    long long a,b;
    int T;
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
}
