#include<stdio.h>
	int main()
		{
			int i,t,a,b,j;
			FILE* c = fopen("euclid2.in","r");
			FILE* d = fopen("euclid2.out","w");
			fscanf(c,"%d",&t);
			for(i=0;i<t;i++)
				{
					fscanf(c,"%d %d",&a,&b);
					rest = a % b;
					while(j!=0)
					{
						a=b;
						b=j;
						j=a%b;
					}
					fprintf(d,"%d \n",a);
				}
			return 0;
		}
