#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b)
{
    if (b==0)
        return a;
    else return cmmdc(b, a%b);
}

int main()
{
    int t, i, x, y;
    fin >> t;
    for (i=1; i<=t; i++)
        {
            fin >> x >> y;
            fout << cmmdc (x, y) << "\n";
        }
    return 0;
}
