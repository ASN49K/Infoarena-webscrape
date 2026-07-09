#include <stdio.h>
#include <stdlib.h>

long int t,a,b;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%ld", &t);
    while(t){
        scanf("%ld", &a);
        scanf("%ld", &b);
        long int r;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        printf("%ld\n", a);
        --t;
    }

    return 0;
}
