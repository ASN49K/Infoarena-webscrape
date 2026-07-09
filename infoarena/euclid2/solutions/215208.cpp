#include<stdio.h>
	int main (){
		int t,a,b,i,r;
		freopen("euclid2.in","r",stdin);
		freopen("euclid2.out","w",stdout);
		scanf("%d",&t);
		for(i=1;i<=t;i++){
			scanf("%d%d",&a,&b);
			while(b!=0){
				r=a%b;
				a=b;
				b=r;
			}
			printf("%d\n",a);
		}
			return 0;
		
	}