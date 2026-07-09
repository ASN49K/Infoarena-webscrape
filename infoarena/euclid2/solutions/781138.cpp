#include <fstream>
using namespace std;

int euclid1(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int euclid2(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    else return cmmdc(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int i, n, a, b;
    fin >> n;
    for (i=1; i<=n; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}
