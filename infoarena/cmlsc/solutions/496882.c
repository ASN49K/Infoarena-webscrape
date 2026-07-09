#include "stdio.h"
	int main()
		{
			int n,m,i;
			FILE* a = fopen("cmlsc.in","r");
			FILE* b = fopen("cmlsc.out","w");
			fscanf(a,"%d %d",&n,&m);
			int c[1024],d[1024],e[1024];	
			for(i=0;i<n;i++)
				{
				fscanf(a,"%d",&c[i]);
				}
			for(i=0;i<m;i++)
				{
				fscanf(a,"%d",&d[i]);
				}
		        int j,max=0;			
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=m;j++)
					if(c[i]==d[j])
						{
						e[max]=c[i];				
						max++;
						}
			}
			fprintf(b,"%d \n",max);
			i=0;
			while(i<max)
				{
					fprintf(b,"%d ",e[i]);
					i++;
				}
		return 0;
		}
