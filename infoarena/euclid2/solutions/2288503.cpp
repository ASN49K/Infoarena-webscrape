#include<stdio.h>
int a,b,r;
int main() {
    freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),scanf("%d",&r);
    for(;scanf("%d%d",&a,&b);printf("%d\n",b)) {
        for(;r=a%b;a=b,b=r);
    }
}
