#include <stdio.h>
#define fr(i,a,b) for(int i=a;i<b;++i)

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b,r;
    scanf("%i",&n);
    fr(i,0,n){
        scanf("%i%i",&a,&b);
        while(b){
            r=a%b;
            a=b;
            b=r;
            }
        printf("%i\n",a);
        }
    return 0;
    }
