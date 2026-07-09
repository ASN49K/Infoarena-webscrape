
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y,x%y);
}
int main()
{
    int x,y,n,i;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>x>>y;
        fout<<gcd(x,y)<<"\n";
    }
    return 0;
}
