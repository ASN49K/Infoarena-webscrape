using namespace std;
#include<cstdio>

int cmmdc(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a        = b;
        b        = temp;
    }

    unsigned int remainder;

    while (b > 0)
    {
        remainder = a % b;
        a         = b;
        b         = remainder;
    }

    return a;
}

int main()
{
    freopen("euclid2.in", "r",stdin);
    freopen("euclid2.out", "w",stdout);
    int a, b, T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
