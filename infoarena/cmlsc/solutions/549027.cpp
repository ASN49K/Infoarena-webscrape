#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *f,*s;

int i,j,k,l,m,n,v1[1100],v2[1100],v3[1100][1100],v4[1100];

int main()
{
	f=fopen("cmlsc.in","r");
	s=fopen("cmlsc.out","w");
	
	fscanf(f,"%d %d",&m,&n);
	
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&v1[i]);
	
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&v2[i]);
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(v1[i]==v2[j])
				v3[i][j]=1+v3[i-1][j-1];
			else	
				v3[i][j]= max(v3[i-1][j],v3[i][j-1]);
		}	
	}	
	
	i=m;
	j=n;
	while(i>0&&j>0)
	{
		if(v1[i]==v2[j])
		{	
			v4[++k]=v1[i];
			
			i--;
			j--;
		}	
		else if (v3[i-1][j]<v3[i][j-1])
			j--;
		else
			i--;
	}
	 

	fprintf(s,"%d\n", k);

	for(i=k;i>0;i--)
		fprintf(s,"%d ",v4[i]);

	fclose(s);
	
	return 0;
}