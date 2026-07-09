#include<stdio.h>
int a,b,r,t;
int main() {
    freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),scanf("%d",&t);
    while(t--) {
        for(scanf("%d%d",&a,&b);r=a%b;a=b,b=r);
        printf("%d\n",b);
    }
}
