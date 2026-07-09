#include <stdio.h>

int T, A, B;


int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T){

        scanf("%d %d", &A, &B);
        while(A != 0)
        {
            int r = A % B;
            A = B;
            B = r;
        }
        printf("%d",A);
        return 0;
    }

    return 0;
}

 