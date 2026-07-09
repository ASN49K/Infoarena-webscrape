#include <bits/stdc++.h>

using namespace std;
int Q;
int cmmdc(int a, int b)
{
    if(b == 0) return a;
    else return cmmdc(b, a % b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &Q);
    while(Q--) {
        int A, B;
        scanf("%d%d", &A, &B);
        printf("%d\n", cmmdc(A, B));
    }
    return 0;
}
