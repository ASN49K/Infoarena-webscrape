#include <stdio.h>
int cmmdc(int a,int b){
    if (b==0)
       return a;
    else return cmmdc(b,a%b);
}
int main(){
    int a,b;
    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);
    scanf("%d%d",&a,&b);
    printf("%d\n",cmmdc(a,b));
    return 0;
}
