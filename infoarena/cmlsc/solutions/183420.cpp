#include<stdio.h>
#define maxim(a,b) ((a>b) ? a:b)
FILE *in=fopen("cmlsc.in","r"),*out=fopen("cmlsc.out","w");
int m,n,mat[1025][1025],v[1025],v2[1025],i,j,lungime,sir[1025];
int main()
{
	fscanf(in,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(in,"%d",&v[i]);
	for(i=1;i<=n;i++)
		fscanf(in,"%d",&v2[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(v[i]==v2[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
		}
	i=m;
	j=n;
	while(i)
	{
		if(v[i]==v2[j])
			{sir[++lungime]=v[i];i--;j--;}
		else if(mat[i-1][j]<mat[i][j-1])
			j--;
		else
			i--;
	}
	fprintf(out,"%d\n",lungime);
	for(i=lungime;i>0;i--)
		fprintf(out,"%d ",sir[i]);
	return 0;
}
