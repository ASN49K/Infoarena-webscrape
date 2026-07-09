#include<stdio.h>
int main()
{
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	
	int a, b, c, t, i;
	
	scanf("%d ", &t);
	for(i=1; i<=t; i++){
		scanf("%d %d ", &a, &b);
	
		if(a<b){
			c=b;
			b=a;
			a=c;
		}
		
		c=a%b;
		
		while(c>0){
			a=b;
			b=c;
			c=a%b;
			if(c==1){
				printf("1\n");
				goto next;
			}
		}
			
		printf("%d\n", b);
		next:;
	}
	
	return 0;
}
