#include<stdio.h>
	int cmmdc(int a, int b)	
		{
			if(!b) return a;
			return cmmdc(b, a%b);
		}
	int main()
		{
			int t,a,b,j=0;
			FILE* c = fopen("euclid2.in","r");
			FILE* d = fopen("euclid2.out","w");
			fscanf(c,"%d",&t);
			for(;t;t--)
				{
					fscanf(c,"%d %d",&a,&b);
					fprintf(d,"%d \n",cmmdc(a,b));
				}
			return 0;
		}
