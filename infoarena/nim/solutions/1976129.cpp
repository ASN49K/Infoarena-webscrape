#include <cstdio>
using namespace std;

int main()
{
    int T, n, nr, q, i, sol;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d", &T);
    for(q = 0;q < T; ++q) {
        scanf("%d%d", &n, &sol);
        for(i = 2;i <= n; ++i) {
            scanf("%d", &nr);
            sol ^= nr;
        }
        if(sol == 0) {
            printf("NU\n");
        }
        else {
            printf("DA\n");
        }
    }
    return 0;
}
