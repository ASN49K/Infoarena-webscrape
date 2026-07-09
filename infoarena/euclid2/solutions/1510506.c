#include <stdio.h>
#include <stdlib.h>
/*Calculate the greatest common divisor of 2 numbers*/
int gcd(int x, int y){

    int aux;

    while(y){
        aux = x;
        x = y;
        y = aux % y;
    }
    return x;
}

int main(void)
{
    freopen("cmmdc.in", "r", stdin);
    freopen("cmmdc.out", "w", stdout);

    int x, y, /*t,*/ gcd_temp;

    //scanf("%d", &t);

    //for(int i = 0; i < t; ++i){
        scanf("%d %d", &x, &y);
        gcd_temp = gcd(x, y);
        if (gcd_temp == 1)
            printf("0");
        else
            printf("%d", gcd_temp);
    //}
    return 0;
}
