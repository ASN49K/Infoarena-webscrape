#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    int t, a ,b, c;
    fin >> t;
    for(int i = 1; i <= t; ++i)
    {
        fin >> a >> b;
        c = cmmdc(a, b);
        fout << c << '\n';
    }
    return 0;
}
