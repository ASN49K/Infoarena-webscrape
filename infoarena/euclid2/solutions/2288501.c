#include<stdio.h>
int a,b,r;
int main() {
    freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),scanf("%d",&a);
    while(scanf("%d%d",&a,&b)) {
        for(;r=a%b;a=b,b=r);
        printf("%d\n",b);
    }
}
