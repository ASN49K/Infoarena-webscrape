#include<stdio.h>
int main(){
	int a,b,t,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%t",&t);
	for(i=1;i<t;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		while(b!=0){
			t=b;
			b=a%b;
			a=t;
		}
		printf("%d\n",a);
	}
	return 0;
}
