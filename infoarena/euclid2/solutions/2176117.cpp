#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    int d;
    while (y)
    {
        d=x%y;
        x=y;
        y=d;
    }
    return x;
}
int t;
int x, y;

int main()
{
    fin>>t;
    for (int i=1;i<=t;++i)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
