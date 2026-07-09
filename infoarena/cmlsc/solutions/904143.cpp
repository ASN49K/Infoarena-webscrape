#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *f,*s;

int i,j,k,m,n;

int v1[1030],v2[1030],v3[1030][1030],v4[1030];

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
				v3[i][j]=v3[i-1][j-1]+1;
			else
				v3[i][j]=max(v3[i-1][j],v3[i][j-1]);
		}
	}		
	
	i=m;
	j=n;
	
	while(i>0 && j>0)
	{
		if(v1[i]==v2[j])
		{
			v4[++k]=v1[i];
			
			i--;
			j--;
		}
		
		if(v3[i-1][j]>v3[i][j-1])
			i--;
		else
			j--;
		
	}
	
	fprintf(s,"%d\n",v3[m][n]);
	
	while(k>0)
	{
		fprintf(s,"%d ",v4[k--]);
	}
	
	fclose(s);
}