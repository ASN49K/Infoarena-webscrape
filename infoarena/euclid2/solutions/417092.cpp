#include <stdio.h>
int main(){
  freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);
  int a,b,r,T;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&a,&b);
    do{ r=a%b; a=b; b=r; } while (r);
    printf("%d\n",a);
  }
return 0;
}