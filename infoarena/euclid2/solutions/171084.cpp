#include<stdio.h>
long a,b,t;
int main()
{long i,r;
 FILE*f=fopen("euclid2.in","r");
 FILE*g=fopen("euclid2.out","w");
 fscanf(f,"%ld",&t);
 for(i=1;i<=t;i++)
	{fscanf(f,"%ld %ld",&a,&b);
	 r=a%b;
	 while(r)
		{a=b;
		 b=r;
		 r=a%b;}
	 fprintf(g,"%ld\n",b);}
 fclose(f);
 fclose(g);
}