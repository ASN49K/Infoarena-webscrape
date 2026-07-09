#include <stdio.h>

int euclid(int a,int b){
if(!b) return a;
 return euclid(b,a%b);
}
int main(){int n;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);int a,b;
for(int i=1;i<=n;i++){
    scanf("%d %d",&a,&b);
    printf("%d ",euclid(a,b));
}
return 0;}
