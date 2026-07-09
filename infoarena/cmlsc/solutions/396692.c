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
	int m,n,i,j,v1[1024],v2[1024],a[1024][1024];
	int max=0,k=0;
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

	for (i=0; i<=max; i++)
		{
			stiva[i].val=-1;
			stiva[i].l=-1;
			stiva[i].c=-1;
		}				
	

	g=fopen("cmlsc.out","w");
	fprintf(g,"%i\n",max);
	
	for (i=0; i<m; i++)
		{
	  	  for (j=0; j<n; j++)
			if (a[i][j]>0)
				{
				  if (stiva[a[i][j]].val!=-1)
					{
				           if (stiva[a[i][j]].c > j && stiva[a[i][j]-1].c < j)
					       {
						stiva[a[i][j]].l=i;
						stiva[a[i][j]].c=j;
						stiva[a[i][j]].val=v1[i];
					       }
					}
				  else
					{
						stiva[a[i][j]].l=i;
						stiva[a[i][j]].c=j;
						stiva[a[i][j]].val=v1[i];
					} 
				}

						
		}
	for (i=1; i<=max; i++)
		fprintf(g,"%i ",stiva[i].val);
	fclose(g);

	return 0;
}

