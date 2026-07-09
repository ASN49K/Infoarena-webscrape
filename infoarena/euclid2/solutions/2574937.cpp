#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int x, int y)
{
    int r;
    r=x%y;
    while (r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int t, a, b;
int main()
{
    fin >> t;
    for (int i=1; i<=t; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    return 0;
}
