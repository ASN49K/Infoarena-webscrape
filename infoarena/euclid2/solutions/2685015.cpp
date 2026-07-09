#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");

    int n;
    int a, b;

    fin >> n;
    for (; n; --n)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
