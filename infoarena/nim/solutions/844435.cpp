#include<fstream>
#include<cstring>

#define Nmax 32

using namespace std;

int n, t, a, maxim, nr, s, sol[Nmax], v[Nmax], put[Nmax];

int main()
{
    ifstream f ("nim.in");
    ofstream h ("nim.out");
    f >> t;

    put[0] = 1;
    for (int i = 1; i <= 32; ++i)
        put[i] = put[i - 1] * 2;

    for (int i = 1; i <= t; ++i)
    {
        f >> n;
        memset (sol, 0, sizeof (sol));
        for (int j = 1; j <= n; ++ j)
        {
            f >> a;
            maxim = 0;
            nr = 0;
            while (a >= 1)
            {
                v[nr] = a % 2;
                ++nr;
                a /= 2;
                v[nr] = a;
            }
            if (nr > maxim)
                maxim = nr;
            for (int k = 0; k <= nr; ++k)
            {
                sol[k] = (sol[k] + v[k]) % 2;
            }
        }
        s = 0;
        for (int p = maxim; p >= 0; --p)
            s += sol[p] * put[p];
        if (s == 0)
            h << "NU\n";
        else
            h << "DA\n";
    }
}
