#include <cstdio>  

int cmmdc (int a,int b)
{
   int r;
   while (a%b != 0) 
   {
	   r = a % b;
	   a = b;
	   b = r;
   }
   return b;
}

void citire()
{
	int a,b,t;
	scanf ("%d",&t);
	for (int i = 1; i <= t; ++i)
	{
		scanf ("%d%d",&a,&b);
		printf ("%d\n",cmmdc(a,b));
	}
}

int main()  
{  
   freopen("euclid2.in","r",stdin);  
   freopen("euclid2.out","w",stdout);  
   citire();
   return 0;  
}
