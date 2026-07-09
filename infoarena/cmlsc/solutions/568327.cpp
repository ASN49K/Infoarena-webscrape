#include<stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int n,m,t[1025],u[1025],l[1025][1025],r[1025][1025],w;
int main()
{
	fscanf(f,"%d%d",&n,&m);
	for(int i=0;i<n;i++)
		fscanf(f,"%d",&t[i]);
	for(int i=0;i<m;i++)
		fscanf(f,"%d",&u[i]);
	int max=0,q=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(t[i]==u[j])
			{
				if(!i||!j)
				{
					l[i][j]=1;
					r[q][0]=w;
					q++;
					w=1;
				}
				else
					l[i][j]=l[i-1][j-1]+1;
				if(max<=l[i][j])
				{
					max=l[i][j];
					r[q][w]=t[i];
					w++;
				}
			}
		}
	r[q][0]=w;
	int ma=0,ii;
	for(int i=0;i<=q;i++)
		if(ma<r[i][0])
		{
			ma=r[i][0];
			ii=i;
		}
	fprintf(g,"%d\n",ma-1);		
	for(int i=1;i<ma;i++)
		fprintf(g,"%d ",r[ii][i]);
	return 0;
}
	
				