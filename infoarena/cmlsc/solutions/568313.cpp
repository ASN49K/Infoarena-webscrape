#include<stdio.h>
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int n,m,t[1025],u[1025],l[1025][1025],r[1025];
int main()
{
	fscanf(f,"%d%d",&n,&m);
	for(int i=0;i<n;i++)
		fscanf(f,"%d",&t[i]);
	for(int i=0;i<m;i++)
		fscanf(f,"%d",&u[i]);
	int max=0,q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(t[i]==u[j])
			{
				if(!i||!j)
				{
					l[i][j]=1;
					q=0;
				}
				else
					l[i][j]=l[i-1][j-1]+1;
				if(max<=l[i][j])
				{
					max=l[i][j];
					r[q]=t[i];
					q++;
				}
			}
	fprintf(g,"%d\n",q);		
	for(int i=0;i<q;i++)
		fprintf(g,"%d ",r[i]);
	return 0;
}
	
				