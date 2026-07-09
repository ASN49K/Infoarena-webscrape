#include "stdio.h"
	int main()
		{
			int n,i;
			FILE* a = fopen("cmlsc.in","r");
			FILE* b = fopen("cmlsc.out","w");
			fscanf(a,"%d",&n);
			int c[n],d[n],e[n];	
			for(i=0;i<n;i++)
				{
				fscanf(a,"%d",&c[i];
				}
			i=0;
			while(!eof(a))
				{
				fscanf(a,"%d",&d[i]);
				i++;	
				}
			int j,k=i,max=0;			
			for(i=0;i<n;i++)
			{
				for(j=0;j<=k;j++)
					if(a[i]==b[k])
						{
							e[max]=a[i];					
							max++;
						}
			}
			fprintf(b,"%d \n ",max);
			i=0;
			while(i<max)
				{
					fprintf(b,"%d ",e[i];
					i++;
				}
		}
