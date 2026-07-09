#include<stdio.h>

int main()
{
	FILE *f=fopen("cmlsc.in","r");
	int m,n,x[1024],y[1024],i,j,c[1025][1025];


	fscanf(f,"%i",&n);
	fscanf(f,"%i",&m);


	for(i=0;i<n;i++)
		fscanf(f,"%i",x+i);	
	


	for(i=0;i<m;i++)
		fscanf(f,"%i",y+i);	
	
	fclose(f);	


	for(i=0;i<=n;i++)
		c[i][0]=0;


	for(j=0;j<=m;j++)
		c[0][j]=0;


	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(x[i]==y[j]) c[i+1][j+1]=c[i][j]+1;
			else
			{ 
				if(c[i+1][j]>c[i][j+1]) c[i+1][j+1]=c[i+1][j];
					else c[i+1][j+1]=c[i][j+1];
			}
		}
	}


	f=fopen("cmlsc.out","w");
	fprintf(f,"%i",c[n][m]);

	return 0;
	}












	
	
	

		

	
	