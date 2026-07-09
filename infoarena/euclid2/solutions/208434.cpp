#include<stdio.h>
int euclid(int a,int b){
	if(b==0)
		return a;
	return euclid(b,a%b);
}
int main(){
	int a,b,n,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}
