#include<stdio.h>   
int t,i,a,b;   
int euclid(int a,int b){
	int c;   
	do{   
		c=a%b;   
		a=b;   
		b=c;   
	}while(c);   
	return a;   
}   
int main(){   
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);   
	for(i=1;i<=t;i++){   
		scanf("%d%d",&a,&b);   
		printf("%d\n",euclid(a,b));   
	}   
	fclose(stdin);   
	fclose(stdout);   
	return 0;   
}  
