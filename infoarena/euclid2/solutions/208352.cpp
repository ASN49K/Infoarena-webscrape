#include<stdio.h>
/*
inline int euclid(int a,int b){
	if(b==0)
		return a;
	return euclid(b,a%b);
}
*/
inline int euclid(int a,int b){
	if(a==b)
		return a;
	if(a>b)
		return euclid(a-b,b);
	return euclid(a,b-a);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}
