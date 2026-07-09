#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for( ; T; --T)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
}
