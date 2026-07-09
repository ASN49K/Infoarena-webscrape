#include <stdio.h>
#include <fstream>
int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
//    freopen("euclid2.in", "r", stdin);
    std::ifstream in; in.open("euclid2.in");
    freopen("euclid2.out", "w", stdout);

    in>>T;
//    scanf("%d", &T);
    for (; T; --T)
    {
        in>>A>>B;
//        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}
