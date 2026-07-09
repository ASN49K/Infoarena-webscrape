#include<stdio.h>
int euclid(int a, int b){
	if(b==0) 
		return a;
	return euclid(b,a%b);
}
int main(){
	int a,b;
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d", euclid(a,b));
	return 0;
}
