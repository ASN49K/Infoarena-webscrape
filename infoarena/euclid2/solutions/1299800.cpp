#include <fstream>

using namespace std;

int euclid(int a, int b);

int main()
{
    int T, a, b;

    ifstream f("euclid2.in");
    f >> T;

    ofstream g("euclid2.out");
    for (int i = 0; i < T; i++)
    {
        f >> a >> b;
        g << euclid(a, b) << '\n';
    }
    f.close();
    g.close();

    return 0;
}

int euclid(int a, int b)
{
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}
