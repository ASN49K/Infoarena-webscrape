#include <stdio.h>

typedef struct
{
	int l,c,val;
} PunctInMatrice;

int maxDeDeasupra(int i, int j, int k, PunctInMatrice stiva[1024])
{
	int t,max=0;
	for (t=0; t<k; t++)
		{
			if (stiva[t].l<i && stiva[t].c<j)
				if (max < stiva[t].val) max=stiva[t].val;
		}
	return max;
}

int main()
{
	int m,n,i,j,v[1025],v1[1024],v2[1024],a[1024][1024];
	int max=0,k=0,t;
	FILE *f,*g;
	PunctInMatrice stiva[1024];

	f=fopen("cmlsc.in","r");
	fscanf(f,"%i%i",&m,&n);
	
	for (i=0; i<m; i++)
		fscanf(f,"%i",&v1[i]);


	for (i=0; i<n; i++)
		fscanf(f,"%i",&v2[i]);

	fclose(f);
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			{
				if (v1[i]!=v2[j]) a[i][j]=0;
				else
				   {
				      a[i][j]=maxDeDeasupra(i,j,k,stiva)+1;
				      stiva[k].l=i;
				      stiva[k].c=j;
				      stiva[k].val=a[i][j];
				      k++;	
				      if (max < a[i][j]) max=a[i][j];
				   }
			}


	g=fopen("cmlsc.out","w");
	fprintf(g,"%i\n",max);
	m--; n--; t=0;
	while (max>0)
		{
			for (i=m; i>=0; i--)
				for (j=n; j>=0; j--)
					if (a[i][j]==max)
						{
							max--;
							m=i;
							n=j;
							t++;
							v[t]=v1[i];
							i=0;
							break;
						}
		}
	for (i=t; i>=1; i--) fprintf(g,"%i ",v[i]);
	fclose(g);

	return 0;
}

