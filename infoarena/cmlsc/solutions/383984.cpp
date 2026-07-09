#include<stdio.h>
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
int v1[1025],v2[1025],max,n1,n2,c[1025][1025],d[1024],k=0;

void rezolvare()
{
	int i,j;

for(i=1;i<=n1;i++)
	for(j=1;j<=n2;j++)
	{
		if(v1[i]==v2[j])
			c[i][j]=1+c[i-1][j-1];
		else
		{
			if(c[i][j-1]>c[i-1][j])
				c[i][j]=c[i][j-1];
			else
				c[i][j]=c[i-1][j];
		}
		
	if(c[i][j]>max)
		max=c[i][j];
	}
}
	
	
void afisare()

{
int i,j;
i=n1;
j=n2;

while(i)
{    
if(v1[i]==v2[j])        
{
d[++k]=v1[i];
i--;
j--;
}
else
if(c[i][j-1]>c[i-1][j])
j--;
else
i--;
}

for(i=c[n1][n2];i>=1;i--)
fprintf(g,"%d ",d[i]);   
}
	
		
	int main()
{
	fscanf(f,"%d %d", &n1,&n2);
	
	int i,j;
	for(i=1;i<=n1;i++)
		fscanf(f,"%d",&v1[i]);
	
	for(i=1;i<=n2;i++)
		fscanf(f,"%d", &v2[i]);
	
	fclose(f);
	rezolvare();
	
	fprintf(g,"%d \n",max);
	afisare();
	
	fclose(g);
	return 0;
}
	
	
