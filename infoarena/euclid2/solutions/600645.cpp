#include <fstream>
using namespace std;

int main()
{
    int i, a, b, ax, n, v[100010];

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(i = 1; i <= n; ++i)
    {
        f >> a >> b;
        while(b)
        {
            ax = a % b;
            a = b;
            b = ax;
        }
        v[i] = a;
    }
    for(i = 1; i <= n; ++i)
        g << v[i] << '\n';

    g.close();
    return 0;
}
