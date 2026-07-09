#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");


int cmmdc(int a, int b)
{
    int r;
    if (b == 0)
        return a;
    r = a % b;
    a = b;
    b = r;
    return cmmdc(a, b);
}

int main()
{
    int t, a, b;
    in >> t;
    for (int i = 1; i <= t; i++)
    {
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }
    return 0;
}