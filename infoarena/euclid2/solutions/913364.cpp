#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int r=a%b;
    while (a%b!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n, a, b;
    f >> n;
    for (int i=0; i<n; i++)
    {
        f >> a >> b;
        g << cmmdc(a, b) << endl;
    }
}
