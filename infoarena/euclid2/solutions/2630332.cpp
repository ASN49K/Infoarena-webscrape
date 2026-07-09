#include <fstream>

using namespace std;

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    ifstream f;
    ofstream g;
    int n, a, b;

    f.open("euclid2.in");
    g.open("euclid2.out");

    f >> n;
    for(int i = 1; i <= n; i++)
    {
        f >> a >> b;
        g << cmmdc(a, b) << endl;
    }

    f.close();
    g.close();
    return 0;
}
