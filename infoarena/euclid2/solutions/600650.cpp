#include <fstream>
using namespace std;

int v[50010];

int main()
{
    int i, a, b, ax, n, t;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;

    t = min(50000, n);

    for(i = 1; i <= t; ++i)
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
    for(i = 1; i <= t; ++i)
        g << v[i] << '\n';

    for(i = t + 1; i <= n; ++i)
    {
        f >> a >> b;
        while(b)
        {
            ax = a % b;
            a = b;
            b = ax;
        }
        v[i - t] = a;
    }

     for(i = t + 1; i <= n; ++i)
        g << v[i - t] << '\n';


    g.close();
    return 0;
}
