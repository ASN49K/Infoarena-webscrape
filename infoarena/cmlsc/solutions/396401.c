#include <stdio.h>

int main()
{
	int m,n,i,j,v1[1024],v2[1024],a[1024][1024];
	int ii,jj,max=0;
	FILE *f,*g;

	f=fopen("cmlsc.in","r");
	fscanf(f,"%i%i",&m,&n);
	
	for (i=0; i<m; i++)
		fscanf(f,"%i",&v1[i]);

	for (i=0; i<n; i++)
		fscanf(f,"%i",&v2[i]);

	fclose(f);
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			a[i][j]=0;


	for (i=m-1; i>=0; i--)
		for (j=n-1; j>=0; j--)
			{
				if (v1[i]==v2[j])
					{
						a[i][j]++;
						if (max<a[i][j]) max=a[i][j];
						for (ii=i; ii>=0; ii--)
							for (jj=j; jj>=0; jj--)
						          if (a[ii][jj]<a[i][j])
							     a[ii][jj]=a[i][j];
					}
			}
	
	g=fopen("cmlsc.out","w");
	fprintf(g,"%i\n",max);
	for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
				if (a[i][j]==max && (v1[i]==v2[j])) 
					{ max--; fprintf(g,"%i ",v1[i]); }
			
		}
	fclose(g);
	return 0;
}

