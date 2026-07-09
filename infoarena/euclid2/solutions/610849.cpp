#include<fstream.h>
int t,A,B,i;
int cmmdc(int a,int b)
{int c,x;
	do{
	if(a>b)
	{c=a;
	a=b;
	b=c%b;}
	else
	{c=b;
	b=a;
	a=c%a;}}while(a!=0&&b!=0);
	if(b==0)
		x=b;
	else
		x=a;
	return (x);
}

main()
{freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&t);

for(i=1;i<=t;i++)
{scanf("%d%d",&A,&B);
printf("%d\n",cmmdc(A,B));}

return (0);
}