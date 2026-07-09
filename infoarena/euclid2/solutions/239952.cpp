#include<stdio.h>
int t,a,b,r;
void cmmdc()
{
	 if(a<b)  
	 {		 
        r=a;     
        a=b;     
		b=r;          
}     
	while(a%b)     
	{     
		r=a%b;     
		a=b;     
		b=r;   
	}
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d",&a,&b);
		cmmdc();
		printf("%d\n",b);
	}
	return 0;
}
