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
				fscanf(a,"%d",&c[i]);
				}
			i=0;
			while(!feof(a))
				{
				fscanf(a,"%d",&d[i]);
				i++;	
				}
			int j,k=i,max=0;			
			for(i=0;i<n;i++)
			{
				for(j=0;j<=k;j++)
					if(c[i]==d[j])
						{
						e[max]=c[i];				
							max++;
						}
			}
			fprintf(b,"%d \n ",max);
			i=0;
			while(i<max)
				{
					fprintf(b,"%d ",e[i]);
					i++;
				}
		return 0;
		}
