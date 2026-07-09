#include<stdio.h>
int t,a,b;

int euclid(int a,int b){
	if(!b) return a;
	return euclid(b,a%b);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}
