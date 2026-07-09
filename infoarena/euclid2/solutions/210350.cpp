#include<stdio.h>
using namespace std;
int cmmdc(int a,int b);
int main()
{
	int a,b,i,x,c;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		scanf("%d%d",&a,&b);
		c=cmmdc(a,b);
		printf("%d\n",c);
	}
	return 0;
}
int cmmdc(int a,int b)
{
	if(a%b==0) return b;
	else return cmmdc(b,a%b);
}

	
