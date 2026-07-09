#include <stdio.h>

unsigned long gcd(long a, long b)
{
    if (a < b) return gcd(b, a);
    
    while (b) {
        unsigned long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void init(const char* input, const char* output)
{
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

int main()
{
    int t, i;
    
    init("euclid2.in", "euclid2.out");
    
    scanf("%d\n", &t);
    for (i = 0; i < t; i++) {
        unsigned long a;
        unsigned long b;
    
        scanf("%lu %lu", &a, &b);
        printf("%lu\n", gcd(a, b));
    }

    return 0;
}
