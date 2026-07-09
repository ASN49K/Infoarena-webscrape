#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    int t, a, b;
    fin>>t;
    for(int i=1;i<=t;++i)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }
}
