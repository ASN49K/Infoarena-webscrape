#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(int a, int b)
{
    if (b==0)
        {
            g << a << endl;
            return;
        }
    cmmdc(b, a%b);
}

int main()
{
    int n, x, y;
    f >> n;
    for (int i=0; i<n; i++)
    {
        f >> x >> y;
        cmmdc(x,y);
    }
    return 0;
}
