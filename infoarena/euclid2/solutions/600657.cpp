#include <fstream>
using namespace std;

#define speedUP (1 << 15)

int main()
{
    register int i, j, a, b, ax, n, t;
    register int v[speedUP + 10];

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;

    for(j = 1; j * speedUP <= n; ++j)
    {
        for(i = 1; i <= speedUP; ++i)
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
        for(i = 1; i <= speedUP; ++i)
            g << v[i] << '\n';
    }

    --j;

    for(i = 1; i <= n - speedUP * j; ++i)
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

    for(i = 1; i <= n - speedUP * j; ++i)
        g << v[i] << '\n';


    g.close();
    return 0;
}
