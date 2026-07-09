#include <fstream>
using namespace std;

int GetCMMDC(int, int);

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int T;
    f >> T;

    int a, b, i;
    for (i = 1; i <= T; i++)
    {
        f >> a >> b;
        g << GetCMMDC(a, b) << endl;
    }

    f.close();
    g.close();
    return 0;
}

int GetCMMDC(int a, int b)
{
    int r;
    r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}
