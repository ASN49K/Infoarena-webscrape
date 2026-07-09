#include <cstdio>

using namespace std;

int main()
{
    FILE *f = fopen("euclid2.in", "r");
    FILE *g = fopen("euclid2.out", "w");

    int n, a, b, r;
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; ++i) {
        fscanf(f, "%d%d", &a, &b);
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(g, "%d\n", a);
    }

    fclose(f);
    fclose(g);
    return 0;
}
