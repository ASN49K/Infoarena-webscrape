#include <stdio.h>
#include <stdlib.h>
/*Calculate the greatest common divisor of 2 numbers*/
int gcd(int x, int y){
    if(!y)
        return x;
    else
        return gcd(y, x % y);
}

int main(void)
{
    freopen("cmmdc.in", "r", stdin);
    freopen("cmmdc.out", "w", stdout);

    int x, y;//, t;

   // scanf("%d", &t);

    //for(int i = 0; i < t; ++i){
        scanf("%d %d", &x, &y);
        printf("%d", gcd(x, y));
    //}
    return 0;
}
