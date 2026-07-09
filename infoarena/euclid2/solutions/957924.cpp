#include <iostream>
#include <stdio.h>

using namespace std;

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
        int minAB = A < B ? A : B;

        for(j= minAB ; j > 2; --j)
        {
            if (A % minAB == 0 && B% minAB == 0)
            {
                printf("%d", j);
                break;
            }
        }
    }

    return 0;
}
