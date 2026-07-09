#include<stdio.h>
int euclid(int a, int b){
	if(b==0) 
		return a;
	return euclid(b,a%b);
}
int main(){
	int a,b,t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	while(t--){
		scanf("%d",&a);
		scanf("%d",&b);
		printf("%d\n", euclid(a,b));
	return 0;
}
