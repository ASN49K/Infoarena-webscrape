#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int n,x,y;
    fin >> n;
    for(int i=1;i<=n;++i)
    {
        fin >> x >> y;
        fout << cmmdc(x,y) << '\n';
    }
    return 0;
}
