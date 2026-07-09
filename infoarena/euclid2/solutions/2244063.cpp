#include <stdio.h>

using namespace std;

int gcd(int a,int b)
{return b==0? a : gcd (b, a%b);}
int main()
{int T,A,B;
freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
 for (scanf("%d", &T); T; --T)
 {scanf("%d %d", &A, &B);
    {printf("%d\n",gcd(A,B));}}

    return 0;
}
