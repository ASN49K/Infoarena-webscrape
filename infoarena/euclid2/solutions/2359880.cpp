#include <iostream>
#include <stdio.h>

using namespace std;

int cmmdc( int A, int B ){
    int R = A % B;
    while( B ){
        R = A % B;
        A = B;
        B = R;
    }
    return A;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n, a, b;
    scanf( "%d", &n );
    for( int i = 1; i <= n; ++ i )
    {
        scanf( "%d%d", &a, &b );
        printf("%d", cmmdc( a, b ));
    }
    return 0;
}
