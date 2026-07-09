#include <stdio.h>
#define NMax 1024
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int i,j,n,m;
int a[NMax],b[NMax],p[NMax][NMax],sol[NMax];


int max(int a,int b) 
{ 
return (a>b)? a:b; 
}

int main(void)
{
    fscanf(f,"%d%d",&n,&m);
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for (j=1;j<=m;j++)
        fscanf(f,"%d",&b[j]);
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
                if (a[i]==b[j]) 
					p[i][j]=1+p[i-1][j-1];
                else 
					p[i][j]=max(p[i-1][j],p[i][j-1]); 
        }
	for (i=1;i<=n;i++)
	{
        for(j=1;j<=m;j++)
			fprintf(g," %d",p[i][j]);
		fprintf(g,"\n");
	}
		fprintf(g,"%d\n",p[n][m]);
    i=n;
    j=m;
    while (i && j)
    {
        if (a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            i--;
            j--;
        }
        else
        {
            if (p[i-1][j]>p[i][j-1])
                i--;
            else j--;
        }
    }
    for (i=sol[0];i>=1;i--)
        fprintf(g,"%d ",sol[i]);
	fprintf(g,"%d %d",m,n);
	fclose(g);
    return 0;
}
