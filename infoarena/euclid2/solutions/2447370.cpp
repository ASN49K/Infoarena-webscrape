#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int d, int i)
{
    if(i==0) return d;
    return gcd(i, d%i);
}
int k,a,b;
int main()
{
    fin>>k;
    while(k--)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
    }
    return 0;
}
