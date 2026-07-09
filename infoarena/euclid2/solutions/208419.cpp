#include<stdio.h>
int euclid(int a, int b){
	if(b==0)
		return a;
	return euclid(b, a%b);
}
int main(){
	freopen("date.in","r,",stdin);
	freopen("date.out","w",stdout);
	int a, b,t,i,rez;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		rez=euclid(a,b);
		printf("%d\n",rez);
		
	}
	return 0;
}
	