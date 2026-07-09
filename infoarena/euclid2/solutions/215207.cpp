#include<stdio.h>
	int main (){
		int t,a,b,i;
		freopen("euclid2.in","r",stdin);
		freopen("euclid2.out","w",stdout);
		scanf("%d",&t);
		for(i=1;i<=t;i++){
			scanf("%d%d",&a,&b);
			while(a!=b)
				if(a>b)
					a=a-b;
				else b=b-a;
			printf("%d\n",a);
		}
			return 0;
		
	}