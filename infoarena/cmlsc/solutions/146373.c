#include<stdio.h>

int main()
{
	FILE *fin=fopen("cmlsc.in","r");
	FILE *fout=fopen("cmlsc.out","w");
	int m,n,x[1024],y[1024],i,j,c[1025][1025];


	fscanf(fin,"%i",&n);
	fscanf(fin,"%i",&m);


	for(i=0;i<n;i++)
		fscanf(fin,"%i",x+i);	
	


	for(i=0;i<m;i++)
		fscanf(fin,"%i",y+i);	
	
	fclose(fin);	


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


	
	fprintf(fout,"%i",c[n][m]);
	fclose(fout);
	
	return 0;
	}












	
	
	

		

	
	