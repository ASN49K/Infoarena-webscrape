#include "stdio.h"
#include "malloc.h"
//#include "dbg.h"

int main()
{
	FILE *f,*g;
	int *v1,*v2,*v,a,b;
	int n1,n2,n;		
	int **m;
	int i,j;
	f=fopen("cmlsc.in","r");
	g=fopen("cmlsc.out","w");
	fscanf(f,"%d%d",&n1,&n2);
	v1 = (int *)malloc(n1*sizeof(int));
	v2 = (int *)malloc(n2*sizeof(int));
	m = (int **)malloc(n1*sizeof(int *)); 
	for(i=0;i<n1;i++)
	{
		fscanf(f,"%d",&v1[i]);
		m[i]=(int *)malloc(n2*sizeof(int));
	}
	for(i=0;i<n2;i++)
		fscanf(f,"%d",&v2[i]);
	if(v1[0]==v2[0])
		m[0][0]=1;
	else
		m[0][0]=0;
	for(i=1;i<n1;i++)
		if(v1[i]==v2[0])
			m[i][0]=1;
		else
			m[i][0]=m[i-1][0];
	
	for(i=1;i<n2;i++)
		if(v2[i]==v1[0])
			m[0][i]=1;
		else
			m[0][i]=m[0][i-1];
	
	for(i=1;i<n1;i++)
		for(j=1;j<n2;j++)
		{
			if(v1[i]==v2[j])
				m[i][j]=m[i-1][j-1]+1;
			else
			{
				a = m[i-1][j];
				b = m[i][j-1];
				m[i][j]=(a>b?a:b);
			}
		}
	n=m[n1-1][n2-1];
	fprintf(g,"%d\n",n);
	v = (int*)malloc(n+sizeof(int));
	i=n1-1;
	j=n2-1;
	n--;
	while((i!=0)&&(j!=0))
	{
		if(m[i][j-1]==m[i][j])
		{
			j--;
			continue;
		}
		if(m[i-1][j]==m[i][j])
		{
			i--;
			continue;
		}
		v[n]=v1[i];
		i--;
		j--;
		n--;
	}
	if(i==0)
		v[0]=v2[j];
	else
		v[0]=v1[i];
	n=m[n1-1][n2-1];
	for(i=0;i<n;i++)
		fprintf(g,"%d ",v[i]);
	
}		
