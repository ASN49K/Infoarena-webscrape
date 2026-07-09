#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    int r = x % y;
    while (r)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int main()
{
    int T, x, y;
    fin>>T;

    while (T--)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
