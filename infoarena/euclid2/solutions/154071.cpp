#include<stdio.h>
int euclid(int a,int b){
	if(!b)
		return a;
	return euclid(b,a%b);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t,a,b;
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
		--t;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
