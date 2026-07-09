#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int n;
    f >> n;
    while (n != 0)
    {
        int a, b;
        f >> a >> b;
        g << cmmdc(a, b) << '\n';
        n--;
    }
}