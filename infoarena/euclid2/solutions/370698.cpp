#include <stdio.h>
long lnko(long a,long b){
long temp;
if(b>a){temp=a;a=b;b=temp;}
while(b!=0){
temp=a%b;
a=b;
 b=temp;
}

return a;
}

int main(){
long t,a,b,i,temp;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%ld",&t);
for(i=1;i<=t;i++){
scanf("%ld %ld",&a,&b);
temp=lnko(a,b);
printf("%d\n",temp);
}
 return 0;
}