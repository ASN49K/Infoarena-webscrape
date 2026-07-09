#include <iostream>
#include <cstdio>

using namespace std;

int euclid(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    int rest = a % b;
    while (rest != 0)
    {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}

int main()
{
    int a, b, t;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
