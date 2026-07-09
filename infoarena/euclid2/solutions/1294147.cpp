#include <cstdio>

using namespace std;

const char iname[] = "euclid2.in";
const char oname[] = "euclid2.out";

int N;

inline int gcd(int a, int b)
{
    int r;
    while(b)    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    FILE *in = fopen(iname, "r");
    FILE *out = fopen(oname, "w");

    fscanf(in, "%d", &N);

    for(int i = 1, a, b; i <= N; ++i) {
        fscanf(in, "%d%d", &a, &b);
        fprintf(out, "%d\n", gcd(a, b));
    }

    return 0;
}
