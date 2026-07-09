#include <cstdio>

using namespace std;

int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, b));
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
