#include <cstdio>
#include <algorithm>
#include <vector>

#define in "euclid2.in"
#define out "euclid2.out"

using namespace std;
int T, a, b;

int cmmdc(int x, int y)
{
    if(x == 0) return y;
    return cmmdc(y%x, x);
}

int main()
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    scanf("%d", &T);
    for(; T; --T)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
