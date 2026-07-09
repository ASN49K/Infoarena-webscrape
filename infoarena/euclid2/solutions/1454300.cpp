#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int x, int y)
{
    int c;
    while (y)
    {
        c = x % y;
        x = y;
        y = c;
    }
}

int main()
{
    long long a,b;
    int n,i;
    fstream f("euclid2.in", ios::in);
    f >> n;
    fstream g("euclid2.out", ios::out);
    for (i = 0; i < n; i++)
    {
        f >> a >> b;
        g << cmmdc(a,b) << endl;
    }
    f.close();
    g.close();
}
