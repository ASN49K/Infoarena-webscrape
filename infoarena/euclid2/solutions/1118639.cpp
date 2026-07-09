#include <cstdio>
using namespace std;

int T, A, B;

int GCD(int A, int B)
{
    if(!B) return A;
    return GCD(B, A % B);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%i", &T);
    for(; T; T --)
    {
        scanf("%i %i", &A, &B);
        printf("%i\n", GCD(A, B));
    }
}
