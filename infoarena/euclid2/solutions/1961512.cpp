#include <iostream>
#include <cstdio>

using namespace std;

int nr;

int euclid(int a, int b)
{
    if (!b)
        return a;
    return euclid(b, a % b);
}

void read()
{
    int a, b;
    scanf("%d\n", &nr);
    for (int i=1; i<=nr; i++)
    {
        scanf("%d %d\n", &a, &b);
        printf("%d\n", euclid(a, b));
    }

}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    read();
    return 0;
}
