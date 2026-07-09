#include<stdio.h>
int euclid(int a, int b){
	if(b==0)
		return a;
	return euclid(b,a%b);
}
int main(){
	int T,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}
