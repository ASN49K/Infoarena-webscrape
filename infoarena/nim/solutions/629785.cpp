#include <cstdio>

FILE *f,*s;

int i,j,k,l,m,n;

int main()
{
	f=fopen("nim.in","r");
	s=fopen("nim.out","w");
	
	fscanf(f,"%d",&n);
	
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d",&m);
		
		l=0;
		for(j=1;j<=m;j++)
		{
			fscanf(f,"%d",&k);
			
			l^=k;
		}
		
		if(l) fprintf(s,"DA\n"); else fprintf(s,"NU\n");
	}	
	
	fclose(s);
	
	return 0;
}