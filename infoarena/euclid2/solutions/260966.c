#include <stdio.h>
int euclid(int a,int b){
	int r=1;
	while(r){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	int n,x,y,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",euclid(x,y));
	}
	return 0;
}
