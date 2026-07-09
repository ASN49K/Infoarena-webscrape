#include <cstdio>

using namespace std;

int main()
{long long a, b, n, i, x;
    FILE * in = fopen("euclid2.in", "r"), * out = fopen("euclid2.out", "w");
    fscanf(in, "%lld", &n);
    for (i = 1; i <= n; ++i)
    {
        fscanf(in, "%lld%lld", &a, &b);
        while (b)
        {
            x = b;
            b = a % b;
            a = x;
        }
        fprintf(out, "%lld\n", a);
    }

    return 0;
}
