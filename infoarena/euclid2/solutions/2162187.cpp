#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, b, r;

int main ()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        while (b>0){
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n", a);
    }
    return 0;
}
