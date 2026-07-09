#include <stdio.h>
#include <stdlib.h>

int a,b,t,i;
int temp;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&a,&b);
        while(b){
            temp=a%b;
            a=b;
            b=temp;
        }
        printf("%d\n",a);
    }
    return 0;
}
