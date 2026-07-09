#include <iostream>
#include <stdio.h>

using namespace std;
#define minim(a, b) ((a < b) ? a : b)
int main()
{
    int T, A, B;
    int i, j ;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for(i=T; i>0; --i)
    {
        scanf("%d %d", &A,&B);


        for(j= minim(A,B); j > 0; j--)
        {
            if (A % j == 0 && B% j == 0)
            {
                printf("%d\n", j);
                break;
            }
        }
    }

    return 0;
}
