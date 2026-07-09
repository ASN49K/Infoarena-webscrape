#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,x,y;

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> T;
    for (;T--;)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }
    return 0;
}
