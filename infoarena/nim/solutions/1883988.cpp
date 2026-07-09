#include <cstdio>
#include <iostream>

using namespace std;

const int nmx = 100002;

int n, v[nmx];

int poz(int nr)
{
    int pt = 1, ps = 0, maxim = -1;

    while(pt <= nr)
    {
        if(pt & nr)
            maxim = ps;
        ++ ps;
        pt <<= 1;
    }

    return maxim;
}

int main()
{
    freopen("joc3.in", "r", stdin);
    freopen("joc3.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    int suma = 0;

    for(int i = 1; i <= n; ++i)
        if(i % 2 != n % 2)
            suma ^= v[i];

    if(suma == 0)
    {
        printf("-1\n");
        return 0;
    }

    int cst = 1 << poz(suma);

    for(int i = 1; i <= n; ++i)
        if(i % 2 != n % 2)
            if(cst & v[i])
            {
                int x = (suma ^ v[i]) - v[i];

                if(x > 0 && x <= v[i-1])
                    printf("%d %d\n", i-1, x);
                else
                    printf("%d %d\n", i, v[i] - (v[i] ^ suma));

                return 0;
            }

    return 0;
}
