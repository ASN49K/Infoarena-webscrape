#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    int i, a, b;

    for (fin >> i; i; i--)
    {
        fin >> a;
        fin >> b;
        //fout << "cmmdc(" << a << "," << b << ")=" << cmmdc(a, b) << "\n";
        fout << cmmdc(a, b) << "\n";
    }

    return 0;
}
