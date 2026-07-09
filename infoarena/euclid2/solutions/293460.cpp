#include<stdio.h>
int n,a,b;
int cmmdc(int,int);
int main(){
freopen("euclid2.in", "r",stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++){scanf("%d %d", &a,&b);
			    printf("%d\n", cmmdc(a,b));}
return 0;}
int cmmdc(int a,int b){if(!b)return a;
					 return (b,a%b);}