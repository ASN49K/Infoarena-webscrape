#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b,r,i,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(i=0; i<t; i++){
        scanf("%d%d",&a,&b);
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",a);
    }

    return 0;
}
