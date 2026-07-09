#include <stdio.h>

int T, a, b;



int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

scanf("%d",&T);
for(int i=0; i<T; i++){
    while(b!=0){
        int rest=a%b;
        a=b;
        b=rest;
    }
    printf("%d",a);
    return 0;
}
}
 