#include<stdio.h>
	void main()
		{
			int t,a,b,j;
			FILE* c = fopen("euclid2.in","r");
			FILE* d = fopen("euclid2.out","w");
			fscanf(c,"%d",&t);
			for(int i=0;i<t;i++)
				{
					fscanf(c,"%d %d",&a,&b);
					while(a!=b)
					{
						if(a>b) a-=b;
						if(b>a)	b-=a;
					}
					fprintf(d,"%d \n",a);
				}
			return 0;
		}
