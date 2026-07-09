#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b) {
    int sw;



    while (a%b != 0){
        a = a%b;

         if (a < b){
            sw = a;
            a = b;
            b = sw;
        }
    }

    return b;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;

    scanf("%d", &t);

    int a,b, sw;
    int result;
    for (int i=0; i<t; i++){
        scanf("%d %d", &a, &b);

         if (a < b){
            sw = a;
            a = b;
            b = sw;
        }

        result = gcd(a,b);
        printf("%d\n", result);
    }


    return 0;
}
