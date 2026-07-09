#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';

    }
    return 0;
}
