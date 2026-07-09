#include<stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int n,m,t[1025],u[1025],l[1025][1025],r[1025],w;
int main()
{
	fscanf(f,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d",&t[i]);
	for(int i=1;i<=m;i++)
		fscanf(f,"%d",&u[i]);
	int max=-1,q=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(t[i]==u[j])
			{
				l[i][j]=l[i-1][j-1]+1;
				if(max<=l[i][j])
				{
					max=l[i][j];
					if(r[q-1]!=t[i])
					{
						r[q]=t[i];
						q++;
					}
				}
			}
			else 
				if(l[i-1][j]>=l[i][j-1])l[i][j]=l[i-1][j];
			else l[i][j]=l[i][j-1];
		}
	fprintf(g,"%d\n",q);		
	for(int i=0;i<q;i++)
		fprintf(g,"%d ",r[i]);
	return 0;
}
	
				