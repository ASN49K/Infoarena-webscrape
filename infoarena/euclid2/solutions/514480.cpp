#include <cstdio>
int main(){
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int t,x,y,tmp;
scanf("%d",&t);
while(t--){
scanf("%d%d",&x,&y);
while(y&&x){
if(y>x){
tmp=y;
y=x;
x=tmp;
}
x=x%y;
}
if(x)printf("%d\n",x);
else printf("%d\n",y);
}
return 0;
}

