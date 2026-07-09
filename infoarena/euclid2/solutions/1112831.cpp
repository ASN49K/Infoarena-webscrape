#include <stdio.h>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T, a, b, tmp;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        //if (b == 0) printf("%d\n", a);
        if (a < b) { tmp = a; a = b; b = tmp; }
        while (b)
        {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        printf("%d\n", a);
    }
    
    return 0;
}
